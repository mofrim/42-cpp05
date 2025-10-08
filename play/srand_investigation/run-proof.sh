#!/usr/bin/env bash

c++ ./inv_srand.cpp -o inv_srand && ./inv_srand > /dev/null && uv run --with "matplotlib" ./plot_data.py

