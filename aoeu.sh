mkdir -p mnt
qmk compile -kb ergohaven/remnant -km j
sudo mount /dev/sdc1 mnt/
sudo cp ./ergohaven_remnant_j.uf2 mnt
sudo umount /dev/sdc1
