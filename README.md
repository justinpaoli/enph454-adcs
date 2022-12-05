# ENPH454-ADCS
This software is designed to run on ADCS hardware as described in the [csdc-4100-adcs-design](https://queensuca.sharepoint.com/:f:/r/teams/GROUP-QSET/Shared%20Documents/Satellite-General/csdc/4000-systems-design/csdc-4100-adcs-design?csf=1&web=1&e=ExKmLO) documents. It was developed for Queen's Space Engineering Team (QSET) as part of the requirements of ENPH 454 - Capstone Engineering Physics Design Project at Queen's University. 

The design team, consisting of:
- Katherine Faulkner
- Jonathan Fawcett
- Cal Graham
- Lily de Loë
- Justin Paoli
- Aidan Sheedy

originally completed this work in the [QSET ADCS respository](https://github.com/queens-satellite-team/adcs). This fork holds a snapshot of the project as of December 2, 2022, when work on the project as part of ENPH 454 was completed.

## adcs-simulation
Holds the 2022-2023 version of the satellite physics simulation. There is one MATLAB Simulink version and one C++ version.

## adcs-control-code
Holds the high-level, hardware agnostic control code. This contains all control algorithms for the ADCS for each mode: pointing mode, fault modes, etc.
