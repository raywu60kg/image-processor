#!/bin/sh
cpplint --linelength=200 --filter=-legal/copyright,-build/include_order --recursive ./src ./tests