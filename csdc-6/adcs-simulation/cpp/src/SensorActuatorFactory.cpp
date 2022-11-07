/** 
 * @file Simulator.cpp
 *
 * @details class file to create the sensor and actuator objects
 *
 * @authors Lily de Loe
 *
 * Last Edited
 * 2022-10-24
 *
**/

#include "sim_interface.hpp"
#include "SensorActuatorFactory.hpp"
#include "ConfigurationSingleton.hpp"
#include "Simulator.hpp"

std::shared_ptr<Sensor> SensorActuatorFactory::GetSensor(const std::string &name) {
    auto &config = Configuration::GetInstance();
    const auto & sensor = config.GetSensorConfig(name);
    
    std::shared_ptr<Sensor> ret;
    if(!sensor)
    {
        return ret;
    }

    switch(sensor->type){
    case SensorType::Accelerometer:
        ret = std::make_shared<Accelerometer>(timestamp(sensor->pollingTime), sensor->position);
        break;
    case SensorType::Gyroscope:
        ret = std::make_shared<Gyroscope>(timestamp(sensor->pollingTime), sensor->position);
        break;
    }
    return ret;
}

std::shared_ptr<Actuator> SensorActuatorFactory::GetActuator(const std::string &name) {
    auto &config = Configuration::GetInstance();
    const auto& actu = config.GetActuatorConfig(name);
    std::shared_ptr<Actuator> ret ;

    if(!actu)
    {
        return ret;
    }

    //this is set up to extend to more actuator types
    switch(actu->type){
    case ActuatorType::ReactionWheel:
        {
            const ReactionWheelConfig* reac = dynamic_cast<const ReactionWheelConfig*>(actu.get());
            actuator_state min;
            min.acceleration = reac->minAngAccel;
            min.velocity = reac->minAngVel;
            min.position = -100000000000000.0f;
            min.time = timestamp(0.0f);
            actuator_state max;
            max.acceleration = reac->maxAngAccel;
            max.velocity = reac->maxAngVel;
            max.position = 10000000000.0f;
            max.time = timestamp(10000000.0f);
            ret = std::make_shared<Reaction_wheel>(timestamp(reac->pollingTime), reac->position, min, max, reac->momentOfInertia);
            break;
        }
    }
    return ret;
}
