#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Erorr: usage: need more arguments! Use --help for more info."
  exit 1
fi

docker run \
  -it \
  --rm \
  -v $PWD:/SAILR \
  sailr-eval "${@:1}" || exit 1

#echo "[+] Done! Remember to update the perms on your results: 'sudo chown \$USER:\$USER -R results'"
sudo chown $USER:$USER -R results/
exit 0
