#!/bin/sh

STACK_FLAGS='
  --compiler ghc-8.10.7
  --system-ghc
  --no-interleaved-output
  --local-bin-path local_bin
'

stack $STACK_FLAGS build && DIST_PATH=$(
  stack $STACK_FLAGS path --dist-dir
) python3 test/internal.py
