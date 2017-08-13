# tinyexe
from ONE LINE CMD to tiny EXE

make one-line-cmd to exe with just ```copy /b tiny.exe + example.bat example.exe```

# how it works
- built tiny.c
- edit the PE file and delete useless part
- merge the .text and move the .data to the end
- fix the offset
- done
