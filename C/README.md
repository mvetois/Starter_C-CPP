# StarterC
C project starter

![GitHub](https://img.shields.io/github/license/mvetois/StarterC?style=flat-square&color=blue)

## Install

### C

For this project you need to install C libraries

```bash
$> sudo apt install build-essential
```

### Criterion

If you want run the unit test of the project you need to installs the tests libraries

```bash
$> sudo add-apt-repository ppa:snaipewastaken/ppa
$> sudo apt update
$> sudo apt install criterion-dev
$> sudo apt install gcovr
```

## Run

### Project

To run the project you need enter this command
```bash
$> make all
$> ./a.out
```

### Unit Tests

To run the project's unit tests you need enter this command
```bash
$> make unit_tests
```

## Credits

- [HeyShafty](https://github.com/HeyShafty) for the Makefile formating