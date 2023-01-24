#!/bin/sh
cpplint --linelength=120 --filter=-legal/copyright,-build/include_order --recursive ./src ./tests