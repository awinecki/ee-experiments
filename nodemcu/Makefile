USB_PORT=/dev/cu.wchusbserial1420


flash: ## Flash firmware to the ESP8266 (preferred >4mb flash)
	## https://nodemcu.readthedocs.io/en/master/en/flash/
	esptool.py --port $(USB_PORT) write_flash -fm dio 0x00000 flash/nodemcu-master-17-modules-2017-03-12-14-41-45-integer.bin

lookup: ## Lookup device chip ID (to check memory etc.)
	## https://code.coreboot.org/p/flashrom/source/tree/HEAD/trunk/flashchips.h
	esptool.py --port $(USB_PORT) flash_id

upload: ## Upload code, pass `file` arg. Ex. `make upload file=init.lua`
	## https://github.com/kmpm/nodemcu-uploader/blob/master/doc/USAGE.md
	nodemcu-uploader --port $(USB_PORT) upload $(file)

ls: ## List files on the device
	nodemcu-uploader --port $(USB_PORT) file list


.PHONY: help flash
.DEFAULT_GOAL := help

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
