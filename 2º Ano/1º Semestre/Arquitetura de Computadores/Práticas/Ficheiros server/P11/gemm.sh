#!/bin/sh
#SBATCH --nodes=1
#SBATCH --tasks=1
#SBATCH --time=00:01:00
#SBATCH --partition=acomp

module load gcc/5.3.0
module load papi/5.4.1

if [ -z $3 ]; then
  echo "Using 1 thread"
  ./gemm $1 $2 1
else
  echo "Using "
  echo $3
  echo " threads";
  ./gemm $1 $2 $3
fi

