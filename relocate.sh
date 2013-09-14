# Simplified from https://gitorious.org/cross-compile-tools/cross-compile-tools

ROOTFS=/home/prabindh/work1/ubuntu-reloc-hardfp12.04
INITIAL_DIR=$PWD

function adjustSymLinks
{
echo "Adjusting the symlinks in $1 to be relative"
cd $1
find . -maxdepth 1 -type l | while read i;
do qualifies=$(file $i | sed -e "s/.*\`\(.*\)'/\1/g" | grep ^/lib)
if [ -n "$qualifies" ]; then
newPath=$(file $i | sed -e "s/.*\`\(.*\)'/\1/g" | sed -e "s,\`,,g" | sed -e "s,',,g" | sed -e "s,^/lib,$2/lib,g");
echo $i
echo $newPath;
sudo rm $i;
sudo ln -s $newPath $i;
fi
done
cd $INITIAL_DIR
}

adjustSymLinks $ROOTFS/usr/lib "../.."
adjustSymLinks $ROOTFS/usr/lib/arm-linux-gnueabihf "../../.."
