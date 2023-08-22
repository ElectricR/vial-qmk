sudo echo ok, now enter boot mode
sleep 5
mkdir -p mnt
qmk compile -kb ergohaven/remnant -km j
sudo mount /dev/sdd1 mnt/
sudo cp ./ergohaven_remnant_j.uf2 mnt
sudo umount /dev/sdd1
