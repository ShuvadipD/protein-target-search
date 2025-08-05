# Compaction of chromatin domains regulates target search times of proteins

[![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by/4.0/)
![Platform](https://img.shields.io/badge/platform-Linux%2FUnix-blue)
![Language](https://img.shields.io/badge/language-C%20%7C%20LAMMPS-orange)

This repository contains simulation codes and plot data for studying how proteins search for target sites on folded chromatin. By combining coarse-grained polymer models with Hi-C-informed contact networks, the simulations investigate how chromatin folding patterns—such as topologically associating domains (TADs) and long-range loops—influence the efficiency and dynamics of protein search.

## Repository Structure

- **`Plot_data`** – Source data files for key figures.  
- **`polymer_simulation`** – LAMMPS input scripts for polymer simulations.  
- **`code_for_mfpt`** – C code to calculate mean first-passage time (MFPT) on a network.

## Requirements

- [LAMMPS](https://www.lammps.org/)
- C compiler (e.g., `gcc`)

## 📚 Reference

If you use this code in your research, please cite the following:

> **Protein search processes mediated by chromatin topology**  
> Shuvadip Dutta, R. Adarshkrishnan, Ranjith Padinhateeri, Mithun K. Mitra  
> *bioRxiv* (2023) doi: [10.1101/2023.12.12.571394](https://doi.org/10.1101/2023.12.12.571394)
