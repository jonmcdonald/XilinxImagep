export TOOL_CHAIN=/store/tools/SDK/2015.4/gnu/arm/lin/bin
export TARGET=arm-xilinx-linux-gnueabi

export CROSS_COMPILE=$TOOL_CHAIN/$TARGET-
export ARCH=arm

if [ ! -d linux-xlnx ]; then
	git clone https://github.com/Xilinx/linux-xlnx.git
	cd linux-xlnx/
	git reset --hard f9d391370402f7428cd12e7aaa5c8ab768ba5332
	cd ..
fi

cp -rf kernel_patches/* linux-xlnx/
cp -rf kernel_patches/.config linux-xlnx/








