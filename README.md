# QtDialogLib
一个封装了Qt ui界面的接口库框架。对外仅暴露C接口，不依赖Qt。外部程序可以通过调用接口弹出Qt实现的各种界面。  
接口库内打包了Qt的resource，如图片、翻译文件等。也可在初始化时传入外部的rcc资源文件路径使用。可根据具体需要自行调整。  
工程为跨平台的版本，Windows和Linux均可使用。  

- 纯C引用示例：testforc  
- Qt引用示例：testforqt  
- Java调用示例：testforJNA  
-- 注意native库需要跟jdk的平台、位数保持一致。且要把Qt依赖库一并放进来（如果系统没有自带Qt）  


### 欢迎提交Pull Request，有用的话请给个Star