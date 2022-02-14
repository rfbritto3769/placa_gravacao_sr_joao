#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../bus_RS232_U2.c ../bus_slave_gr.c "../Gravador USB.c" ../Memoria.c ../PIC_Prog_16F.c ../PIC_Prog_16F1XXX.c ../PIC_Prog_16F6XX.c ../PIC_Prog_16F506.c ../PIC_Prog_24FJ.c ../ProgExecutive.c ../recebe_arq.c ../PIC_Prog_16F153XX.c ../grava_pic16f15344.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/bus_RS232_U2.o ${OBJECTDIR}/_ext/1472/bus_slave_gr.o "${OBJECTDIR}/_ext/1472/Gravador USB.o" ${OBJECTDIR}/_ext/1472/Memoria.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o ${OBJECTDIR}/_ext/1472/ProgExecutive.o ${OBJECTDIR}/_ext/1472/recebe_arq.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/bus_RS232_U2.o.d ${OBJECTDIR}/_ext/1472/bus_slave_gr.o.d "${OBJECTDIR}/_ext/1472/Gravador USB.o.d" ${OBJECTDIR}/_ext/1472/Memoria.o.d ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o.d ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o.d ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o.d ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o.d ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o.d ${OBJECTDIR}/_ext/1472/ProgExecutive.o.d ${OBJECTDIR}/_ext/1472/recebe_arq.o.d ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o.d ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/bus_RS232_U2.o ${OBJECTDIR}/_ext/1472/bus_slave_gr.o ${OBJECTDIR}/_ext/1472/Gravador\ USB.o ${OBJECTDIR}/_ext/1472/Memoria.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o ${OBJECTDIR}/_ext/1472/ProgExecutive.o ${OBJECTDIR}/_ext/1472/recebe_arq.o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o

# Source Files
SOURCEFILES=../bus_RS232_U2.c ../bus_slave_gr.c ../Gravador USB.c ../Memoria.c ../PIC_Prog_16F.c ../PIC_Prog_16F1XXX.c ../PIC_Prog_16F6XX.c ../PIC_Prog_16F506.c ../PIC_Prog_24FJ.c ../ProgExecutive.c ../recebe_arq.c ../PIC_Prog_16F153XX.c ../grava_pic16f15344.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA006
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA006.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/bus_RS232_U2.o: ../bus_RS232_U2.c  .generated_files/flags/default/253a8f2812763da13aa13778776dd20febf2572f .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/bus_RS232_U2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/bus_RS232_U2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../bus_RS232_U2.c  -o ${OBJECTDIR}/_ext/1472/bus_RS232_U2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/bus_RS232_U2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/bus_slave_gr.o: ../bus_slave_gr.c  .generated_files/flags/default/9dfc9ec3da829d207c28b758997fb2b3538a7e92 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/bus_slave_gr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/bus_slave_gr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../bus_slave_gr.c  -o ${OBJECTDIR}/_ext/1472/bus_slave_gr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/bus_slave_gr.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/Gravador\ USB.o: ../Gravador\ USB.c  .generated_files/flags/default/1e5b51abf8ccdaf2b96cef5838473877b9545bae .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} "${OBJECTDIR}/_ext/1472/Gravador USB.o".d 
	@${RM} "${OBJECTDIR}/_ext/1472/Gravador USB.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Gravador USB.c"  -o "${OBJECTDIR}/_ext/1472/Gravador USB.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/Gravador USB.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/Memoria.o: ../Memoria.c  .generated_files/flags/default/af616a6099897e7b0f491df37720a972848aeecd .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Memoria.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Memoria.c  -o ${OBJECTDIR}/_ext/1472/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/Memoria.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o: ../PIC_Prog_16F.c  .generated_files/flags/default/a53bc46b5b4c9ace9ec50daadfc5d1636142c4d7 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o: ../PIC_Prog_16F1XXX.c  .generated_files/flags/default/bdb9f68d72a07ce49e0bb98b65c6a324031b1c90 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F1XXX.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o: ../PIC_Prog_16F6XX.c  .generated_files/flags/default/afda1c9771706dadb8be8aa0f06df3ec520aa53e .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F6XX.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o: ../PIC_Prog_16F506.c  .generated_files/flags/default/b8f19fdd0bf35d723d07e24a73792709b45ba649 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F506.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o: ../PIC_Prog_24FJ.c  .generated_files/flags/default/b3f4393491232d3143c16062382e1268231b063a .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_24FJ.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/ProgExecutive.o: ../ProgExecutive.c  .generated_files/flags/default/c0116ed410ca350f80592e7c0b0c40b270e0dff3 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ProgExecutive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ProgExecutive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ProgExecutive.c  -o ${OBJECTDIR}/_ext/1472/ProgExecutive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ProgExecutive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/recebe_arq.o: ../recebe_arq.c  .generated_files/flags/default/e2d51866369081a4ef3b2da0e54d411b9b4aaf5d .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/recebe_arq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/recebe_arq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../recebe_arq.c  -o ${OBJECTDIR}/_ext/1472/recebe_arq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/recebe_arq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o: ../PIC_Prog_16F153XX.c  .generated_files/flags/default/1358675f6c3f1f0c195ad368fc250580364bc45c .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F153XX.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/grava_pic16f15344.o: ../grava_pic16f15344.c  .generated_files/flags/default/1cd11c4a6afa822d336a1571b14a39cc7ba9237e .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../grava_pic16f15344.c  -o ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/grava_pic16f15344.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1472/bus_RS232_U2.o: ../bus_RS232_U2.c  .generated_files/flags/default/80a64c15f7808bfce3565282f304baf90876a8bb .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/bus_RS232_U2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/bus_RS232_U2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../bus_RS232_U2.c  -o ${OBJECTDIR}/_ext/1472/bus_RS232_U2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/bus_RS232_U2.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/bus_slave_gr.o: ../bus_slave_gr.c  .generated_files/flags/default/79cbb0a87e1cfd32595470eb4216cf9153679a37 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/bus_slave_gr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/bus_slave_gr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../bus_slave_gr.c  -o ${OBJECTDIR}/_ext/1472/bus_slave_gr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/bus_slave_gr.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/Gravador\ USB.o: ../Gravador\ USB.c  .generated_files/flags/default/27f9879d8b7f84dd8e5cf68c9e7edf55c9845e67 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} "${OBJECTDIR}/_ext/1472/Gravador USB.o".d 
	@${RM} "${OBJECTDIR}/_ext/1472/Gravador USB.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Gravador USB.c"  -o "${OBJECTDIR}/_ext/1472/Gravador USB.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/Gravador USB.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/Memoria.o: ../Memoria.c  .generated_files/flags/default/cb5a6636b6612c96ca7d61afbc37ed0b879359c2 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Memoria.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Memoria.c  -o ${OBJECTDIR}/_ext/1472/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/Memoria.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o: ../PIC_Prog_16F.c  .generated_files/flags/default/b0694f1cdec0158f788c09297e917b2548e432aa .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o: ../PIC_Prog_16F1XXX.c  .generated_files/flags/default/c6d9b4eec9bfd442a0e2e6c82a08241e79fea5c7 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F1XXX.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F1XXX.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o: ../PIC_Prog_16F6XX.c  .generated_files/flags/default/d2a50b012b84103cb0ce6845033f926dfc147243 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F6XX.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F6XX.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o: ../PIC_Prog_16F506.c  .generated_files/flags/default/d6753ef54b50f5854e03edc3b3f2dc200d3dac47 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F506.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F506.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o: ../PIC_Prog_24FJ.c  .generated_files/flags/default/299701bee6a500b86b8a410156e3fabae5b8318f .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_24FJ.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_24FJ.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/ProgExecutive.o: ../ProgExecutive.c  .generated_files/flags/default/58ba4a8eb511837fcd9d0554ebd276a77d2dd4bf .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ProgExecutive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ProgExecutive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ProgExecutive.c  -o ${OBJECTDIR}/_ext/1472/ProgExecutive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ProgExecutive.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/recebe_arq.o: ../recebe_arq.c  .generated_files/flags/default/c1d18ebc75e97a7ad23c2b5cb8bfe81f70c18ae1 .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/recebe_arq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/recebe_arq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../recebe_arq.c  -o ${OBJECTDIR}/_ext/1472/recebe_arq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/recebe_arq.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o: ../PIC_Prog_16F153XX.c  .generated_files/flags/default/200e675f5b1849732230a5f5e399607f99df5e6f .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC_Prog_16F153XX.c  -o ${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PIC_Prog_16F153XX.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/grava_pic16f15344.o: ../grava_pic16f15344.c  .generated_files/flags/default/7557e27709988af2b1fa10a0e2e513b460e0f7ea .generated_files/flags/default/37e7e872b2ece7999d79c50cf5dabd51d3e3a4b3
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../grava_pic16f15344.c  -o ${OBJECTDIR}/_ext/1472/grava_pic16f15344.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/grava_pic16f15344.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -O0 -I".." -I"." -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD4=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Placa_Gravacao_Universal.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
