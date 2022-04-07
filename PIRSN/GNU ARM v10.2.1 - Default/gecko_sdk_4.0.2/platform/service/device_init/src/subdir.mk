################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/EXTR\ 1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.c \
C:/Users/EXTR\ 1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_emu_s2.c \
C:/Users/EXTR\ 1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_hfxo_s2.c \
C:/Users/EXTR\ 1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_nvic.c 

OBJS += \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.o \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.o \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.o \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.o 

C_DEPS += \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.d \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.d \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.d \
./gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.o: C:/Users/EXTR\ 1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DSENSOR_ROLE=1' '-DEFR32FG23B010F512IM40=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DEMBER_STACK_CONNECT=1' '-DCORTEXM3=1' '-DCORTEXM3_EFM32_MICRO=1' '-DCORTEXM3_EFR32=1' '-DPHY_RAIL=1' '-DPLATFORM_HEADER="platform-header.h"' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CLIENT=1' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DCUSTOM_TOKEN_HEADER="sl_token_manager_af_token_header.h"' '-DUSE_NVM3=1' -I"C:\Users\█████████\Desktop\I2DS\PIRSN" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG23/Include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/cli/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/app-framework-common" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/debug-print" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/poll" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/stack" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/stack/include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/driver/leddrv/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/legacy_hal/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg23" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/flex/component/connect/sl_sensor_sink" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/token_manager/inc" -I"C:\Users\█████████\Desktop\I2DS\PIRSN\autogen" -I"C:\Users\█████████\Desktop\I2DS\PIRSN\config" -O1 -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_dcdc_s2.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.o: C:/Users/EXTR\ 1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_emu_s2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DSENSOR_ROLE=1' '-DEFR32FG23B010F512IM40=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DEMBER_STACK_CONNECT=1' '-DCORTEXM3=1' '-DCORTEXM3_EFM32_MICRO=1' '-DCORTEXM3_EFR32=1' '-DPHY_RAIL=1' '-DPLATFORM_HEADER="platform-header.h"' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CLIENT=1' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DCUSTOM_TOKEN_HEADER="sl_token_manager_af_token_header.h"' '-DUSE_NVM3=1' -I"C:\Users\█████████\Desktop\I2DS\PIRSN" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG23/Include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/cli/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/app-framework-common" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/debug-print" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/poll" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/stack" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/stack/include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/driver/leddrv/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/legacy_hal/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg23" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/flex/component/connect/sl_sensor_sink" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/token_manager/inc" -I"C:\Users\█████████\Desktop\I2DS\PIRSN\autogen" -I"C:\Users\█████████\Desktop\I2DS\PIRSN\config" -O1 -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_emu_s2.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.o: C:/Users/EXTR\ 1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_hfxo_s2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DSENSOR_ROLE=1' '-DEFR32FG23B010F512IM40=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DEMBER_STACK_CONNECT=1' '-DCORTEXM3=1' '-DCORTEXM3_EFM32_MICRO=1' '-DCORTEXM3_EFR32=1' '-DPHY_RAIL=1' '-DPLATFORM_HEADER="platform-header.h"' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CLIENT=1' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DCUSTOM_TOKEN_HEADER="sl_token_manager_af_token_header.h"' '-DUSE_NVM3=1' -I"C:\Users\█████████\Desktop\I2DS\PIRSN" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG23/Include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/cli/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/app-framework-common" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/debug-print" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/poll" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/stack" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/stack/include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/driver/leddrv/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/legacy_hal/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg23" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/flex/component/connect/sl_sensor_sink" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/token_manager/inc" -I"C:\Users\█████████\Desktop\I2DS\PIRSN\autogen" -I"C:\Users\█████████\Desktop\I2DS\PIRSN\config" -O1 -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_hfxo_s2.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.o: C:/Users/EXTR\ 1/SimplicityStudio/SDKs/gecko_sdk/platform/service/device_init/src/sl_device_init_nvic.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DSENSOR_ROLE=1' '-DEFR32FG23B010F512IM40=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DEMBER_STACK_CONNECT=1' '-DCORTEXM3=1' '-DCORTEXM3_EFM32_MICRO=1' '-DCORTEXM3_EFR32=1' '-DPHY_RAIL=1' '-DPLATFORM_HEADER="platform-header.h"' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CLIENT=1' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DCUSTOM_TOKEN_HEADER="sl_token_manager_af_token_header.h"' '-DUSE_NVM3=1' -I"C:\Users\█████████\Desktop\I2DS\PIRSN" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG23/Include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/cli/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/app-framework-common" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/debug-print" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/poll" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/stack" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/stack/include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/host/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/driver/leddrv/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/legacy_hal/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg23" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//app/flex/component/connect/sl_sensor_sink" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/█████████/SimplicityStudio/SDKs/gecko_sdk//platform/service/token_manager/inc" -I"C:\Users\█████████\Desktop\I2DS\PIRSN\autogen" -I"C:\Users\█████████\Desktop\I2DS\PIRSN\config" -O1 -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.d" -MT"gecko_sdk_4.0.2/platform/service/device_init/src/sl_device_init_nvic.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


