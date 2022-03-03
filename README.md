# C51-LCD-BadApple
大一疫情在家时做的一个十分简单的项目，实现原理也并不复杂。

用potplayer的自动截图功能将视频截图为许多图像，用Photoshop的自动处理功能将每张图像缩放到96\*64，在图像左右两侧留白，图像的大小就变为128\*64了，将图像保存为bmp文件。再用Image2lcd把bmp转化为二进制的bin。最后，用一个叫做binHEBING的工具将所有二进制文件合并为一个bin文件，这就是放进SD卡里的数据文件了。

![Image2lcd](.\images\Image2lcd.png)

而SD卡、LCD的驱动都是网上抄过来的。当初学艺不精，码风不佳，工程的结构也乱了点，并且在播放帧切换的时候会出现锯齿。效果只能说差强人意。

运行截图：

![screenshot](.\images\screenshot.png)

效果视频：https://www.bilibili.com/video/BV1x7411z7te/

