# How to completely remove an application
## Description:
## Reference:[click](http://askubuntu.com/questions/187888/what-is-the-correct-way-to-completely-remove-an-application))
## Solution
1.will remove the binaries, but not the configuration or data files of the package packagename. It will also leave dependencies installed with it on installation time untouched:
<!--lang:bash-->
    apt-get remove packagename
2.copy kengen to the server
<!--lang:bash-->
    apt-get purge packagename
or
<!--lang:bash-->
    apt-get remove --purge packagename
