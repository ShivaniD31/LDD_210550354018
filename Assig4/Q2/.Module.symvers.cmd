cmd_/home/pi/device-drivers/native/Assig4/Q2/Module.symvers := sed 's/ko$$/o/' /home/pi/device-drivers/native/Assig4/Q2/modules.order | scripts/mod/modpost -m -a   -o /home/pi/device-drivers/native/Assig4/Q2/Module.symvers -e -i Module.symvers   -T -
