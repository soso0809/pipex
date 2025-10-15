#!/bin/bash
rm -r "pipex-tester/"
rm -r "pipex_tester_42/"
make fclean >/dev/null 2>&1 || true
rm -r "$0"
