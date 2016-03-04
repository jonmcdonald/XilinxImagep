
if [ ! -d buildroot-2013.02 ]; then
	wget https://buildroot.org/downloads/buildroot-2013.02.tar.gz
	tar xvf buildroot-2013.02.tar.gz
fi

cp -rf buildroot_patches/etc buildroot-2013.02/system/skeleton
cp -f buildroot_patches/.config buildroot-2013.02/
cp -f buildroot_patches/busybox-config buildroot-2013.02/

mkdir -p buildroot-2013.02/system/skeleton/home/root

