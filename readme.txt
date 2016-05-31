                             内 核 更 新 说 明
1.2015年1月29日打上了以下补丁(支持单5V系统运行)：
    L2.6.35_10.12_EMI_FREQ_PATCH_UP.tar.gz
    L2.6.35_10.12_SDK_5V_SUPPLY_PATCH.tar.gz
    MX28-FEC-PROBLEM-PATCH.tar.gz
    patches_for_L2.6.35_MX28_SDK_10.12_SOURCE.tar.gz
    0001-MX28-L2.6.35_1.1.0-lcdif_set_rate-fix.patch.zip
2.解决了开机时企鹅图标闪烁问题（减少液晶初始化次数、禁止在系统启动时改变CPU频率）
3.修改了LCD接口时钟源，允许pix_clk大于24MHz
4.去掉了PHY驱动中错误的I/O引用
5.配置为双以太网时PHY为逆序扫描（适用于PHY0地址大于PHY1地址）
6.修改PWM驱动，支持频率修改

附录：2015年1月29日对应具体的补丁文件如下：
    0001-MX28-L2.6.35_1.1.0-lcdif_set_rate-fix.patch
    0001-ENGR00000000-Workaround-for-bus-freq-change.patch
    0001-ENGR00137130-Fec-MDIO-timeout-at-bootup-or-plugin-ca.patch
    0002-ENGR00182409-MX28-some-MX28-EVK-eth0-doesn-t-work.patch
    0004-MX28-kernel-5V-only-configuration-bug-fixes-and-improvement.patch
    0572-ENGR00137224-L2Switch-Fix-L2Switch-port-learn-not-ta.patch
    0573-ENGR00137979-1-MX28-add-performance-monitor-driver.patch
    0574-ENGR00137979-2-add-performance-monitor-driver.patch
    0575-ENGR00137161-MX28-MSL-PSWITCH-interrupt-should-be-en.patch
    0576-ENGR00137418-MX28-fix-aplay-has-no-sound-after-suspe.patch
    0577-ENGR38635466-mx28-add-auart4-rx-resource.patch
    0578-ENGR00140699-1-mxs-spi-support-spi-slave-mode.patch
    0579-ENGR00140699-2-mx28-spi-add-a-parameter-to-select-sp.patch
    0580-ENGR00142095-MX28-Slow-down-HBUS-freq-in-suspend.patch
    0581-ENGR38811709-MX28-GPIO-bank0-irq.patch
    0582-ENGR00151750-MX28-MMC-SDIO-add-polling-mode-for-fast.patch
    0583-ENGR00142099-1-MXS-Add-fastpath-parameter-in-mxs_mmc.patch
    0584-ENGR00142099-2-MX233-MX28-Change-AC-BC-command-to-PI.patch
    0585-ENGR00142099-3-MX233-MX28-implement-fastpath-in-driv.patch
    0586-ENGR00142099-4-MX233-MX28-implement-SG-DMA-in-driver.patch
    0587-ENGR00142099-5-MX233-MX28-fix-sdio-irq-issue.patch
    0588-ENGR00152131-MX28-Suspend-resume-defect.patch
    0589-ENGR00152560-MX233-MX28-mxs-mmc-fix-clock-rate-setti.patch
    0590-ENGR00155144-1-mx28-usb-bugs-found.patch
    0591-ENGR00155144-2-mx28-usb-bugs-found.patch
    0592-ENGR38993445-1-UART-driver-Fix-bit-setting-for-flow-.patch
    0593-ENGR38993445-2-AUART-Serial-device-platform-configur.patch
    0594-ENGR38993445-3-AUART-Optimizations-for-UART-driver-R.patch
    0595-ENGR38993445-4-AUART-fix-compiling-error.patch
    patch_fix_image_jump_around.patch



                                                   2015.01.29 hak
