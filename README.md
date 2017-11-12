# JPEG-to-AVI
这个是修改别人的程序得来的；
将指定目录下的.jpg图片集排序后转化成AVI视频，并可以指定帧率（-f 帧/s），指定图片目录(-i 图片集地址)，指定输出文件地址(-o 输出文件地址)
# 修改
增加了read_file函数，可以从指定路径读取.jpg文件并按照文件名从小到大排列后存放到容器内；
# 指令
cd JPEG-to-AVI

make

./bin/mjpeg -i ./data/test/ -o ./output/output.avi -f 8

## MIT-like License

Copyright (c) 2011 Adam Strzelecki

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
