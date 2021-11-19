1、.pro文件中带上这两行,支持utf-8源码
QMAKE_CFLAGS += /utf-8
QMAKE_CXXFLAGS += /utf-8

2、添加外部工具一键打包
执行档 %{CurrentProject:QT_HOST_BINS}\windeployqt.exe
参数 %{CurrentRun:Executable:FilePath}
工作目录 %{CurrentRun:Executable:NativePath}