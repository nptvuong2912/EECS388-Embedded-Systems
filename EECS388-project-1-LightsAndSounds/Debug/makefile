################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_5.2.2

ORDERED_OBJS += \
"./main.obj" \
"./targetConfigs/lm3s1968_startup_ccs.obj" \
"./src/led.obj" \
"./src/oled.obj" \
"./src/speaker.obj" \
"./src/system.obj" \
"./src/OLED_Driver/rit128x96x4.obj" \
"../targetConfigs/lm3s1968.cmd" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \
-l"C:\TI_CodeComposer\StellarisWare-LM3S1968\driverlib\ccs-cm3\Debug\driverlib-cm3.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include targetConfigs/subdir_vars.mk
-include src/subdir_vars.mk
-include src/OLED_Driver/subdir_vars.mk
-include subdir_rules.mk
-include targetConfigs/subdir_rules.mk
-include src/subdir_rules.mk
-include src/OLED_Driver/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
EECS_388_P01.out \

EXE_OUTPUTS__QUOTED += \
"EECS_388_P01.out" \

BIN_OUTPUTS += \
EECS_388_P01.bin \

BIN_OUTPUTS__QUOTED += \
"EECS_388_P01.bin" \


# All Target
all: EECS_388_P01.out

# Tool invocations
EECS_388_P01.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib --abi=eabi -me -g --gcc --define=CCS6_ARMCM3 --define="ccs" --define=PART_LM3S1968 --display_error_number --emit_warnings_as_errors --diag_suppress=179 --diag_wrap=off --printf_support=full -z -m"EECS_388_P01.map" --heap_size=4096 --stack_size=4096 -i"C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/lib" -i"C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" --reread_libs --warn_sections --display_error_number --emit_warnings_as_errors --xml_link_info="EECS_388_P01_linkInfo.xml" --rom_model -o "EECS_388_P01.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

EECS_388_P01.bin: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armhex"  -o "EECS_388_P01.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "main.pp" "targetConfigs\lm3s1968_startup_ccs.pp" "src\led.pp" "src\oled.pp" "src\speaker.pp" "src\system.pp" "src\OLED_Driver\rit128x96x4.pp" 
	-$(RM) "main.obj" "targetConfigs\lm3s1968_startup_ccs.obj" "src\led.obj" "src\oled.obj" "src\speaker.obj" "src\system.obj" "src\OLED_Driver\rit128x96x4.obj" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-"C:/TI_CodeComposer/ccsv6/utils/tiobj2bin/tiobj2bin" "EECS_388_P01.out" "EECS_388_P01.bin" "C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armofd" "C:/TI_CodeComposer/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armhex" "C:/TI_CodeComposer/ccsv6/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

