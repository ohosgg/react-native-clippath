> 模板版本：v0.1.3

<p align="center">
  <h1 align="center"> <code>react-native-clippath</code> </h1>
 </p>  
<p align="center">
<a href="https://github.com/Only-IceSoul/react-native-clippath">
        <img src="https://img.shields.io/badge/platforms-android%20|%20ios%20|%20web|%20harmony%20-lightgrey.svg" alt="Supported platforms" />
    </a>
    <a href="https://github.com/Only-IceSoul/react-native-clippath/blob/main/LICENSE">
        <img src="https://img.shields.io/badge/license-MIT-green.svg" alt="License" />
    </a>
</p>

> [!TIP] [Github 地址](https://github.com/react-native-oh-library/react-native-clippath)


## 安装与使用

请到三方库的 Releases 发布地址查看配套的版本信息：[@react-native-oh-tpl/react-native-clippath Releases](https://github.com/react-native-oh-library/react-native-clippath/releases)，并下载适用版本的 tgz 包。

进入到工程目录并输入以下命令：

> [!TIP] # 处替换为 tgz 包的路径

<!-- tabs:start -->

#### **npm**

```bash
npm install @react-native-oh-tpl/react-native-clippatht@file:#
```

#### **yarn**

```bash
yarn add @react-native-oh-tpl/react-native-clippath@file:#
```

<!-- tabs:end -->

下面的代码展示了这个库的基本使用场景：

> [!WARNING] 使用时 import 的库名不变。

```js
import {View, StyleSheet,Image,Dimensions, ScrollView,Text} from 'react-native';
import {ClipPathView} from 'react-native-clippath';

const ClipPathViewDemo = () => {
    return (
    <View>
    <ScrollView>
    <View style = {styles.viewItem}>
<Text>AAAAABBBBBCCCCCDDDDDEEEEEFFFFFHHHHHIIIIIJJJJJKKKKKLLLLLMMMMMNNNNN</Text>
    </View>

    <ClipPathView
d="M 0 0 L 0 0 L 0 50 L 50 50 L 50 0  Z"
>
<View style = {styles.viewItem}>
<Text>AAAAABBBBBCCCCCDDDDDEEEEEFFFFFHHHHHIIIIIJJJJJKKKKKLLLLLMMMMMNNNNN</Text>
    </View>
    </ClipPathView>
    <ClipPathView
d="M 0 0 L 0 0 L 0 50 L 50 50 L 50 0  Z"

rot={30}
rotOx={10}
rotOy={10}
rotPercentageValue={true}
>
<View style = {styles.viewItem}>
<Text>AAAAABBBBBCCCCCDDDDDEEEEEFFFFFHHHHHIIIIIJJJJJKKKKKLLLLLMMMMMNNNNN</Text>
    </View>
    </ClipPathView>

    <ClipPathView
d="M 0 0 L 0 0 L 0 50 L 50 50 L 50 0  Z"
sc={2}
>
<View style = {styles.viewItem}>
<Text>SSAAAAABBBBBCCCCCDDDDDEEEEEFFFFFHHHHHIIIIIJJJJJKKKKKLLLLLMMMMMNNNNN</Text>
    </View>
    </ClipPathView>
    <ClipPathView
d="M 0 0 L 0 0 L 0 50 L 50 50 L 50 0  Z"
scX={1.2}
scY={1.3}
>
<View style = {styles.viewItem}>
<Text>SSAAAAABBBBBCCCCCDDDDDEEEEEFFFFFHHHHHIIIIIJJJJJKKKKKLLLLLMMMMMNNNNN</Text>
    </View>
    </ClipPathView>
    <ClipPathView
d="M 0 0 L 0 0 L 0 50 L 50 50 L 50 0  Z"
transPercentageValue={true}
transX = {50}
transY = {50}>
<View style = {styles.viewItem}>
<Text>TTAAAAABBBBBCCCCCDDDDDEEEEEFFFFFHHHHHIIIIIJJJJJKKKKKLLLLLMMMMMNNNNN</Text>
    </View>
    </ClipPathView>
    </ScrollView>
    </View>
);
};


const styles = StyleSheet.create({
    containerBase:{
        backgroundColor:'black',
        justifyContent:'center',
        margin:2
    },
    viewItem: {
        width: Dimensions.get('window').width/2 - 2,
        height: Dimensions.get('window').height/4 - 10,
        borderWidth:2,
        margin:2,
        flexWrap:'wrap',
        flexDirection:'row',
    },
    logo: {
        width: Dimensions.get('window').width/2 - 2,
        height: Dimensions.get('window').height/4 - 10,
        borderWidth:2
    }
});

export default ClipPathViewDemo;
```
## Link

目前鸿蒙暂不支持 AutoLink，所以 Link 步骤需要手动配置。

首先需要使用 DevEco Studio 打开项目里的鸿蒙工程 `harmony`

### 在工程根目录的 `oh-package.json` 添加 overrides字段

```json
{
  ...
  "overrides": {
    "@rnoh/react-native-openharmony" : "./react_native_openharmony"
  }
}
```

### 引入原生端代码

目前有两种方法：

1. 通过 har 包引入（在 IDE 完善相关功能后该方法会被遗弃，目前首选此方法）；
2. 直接链接源码。

方法一：通过 har 包引入（推荐）

> [!TIP] har 包位于三方库安装路径的 `harmony` 文件夹下。

打开 `entry/oh-package.json5`，添加以下依赖

```json
"dependencies": {
    "@rnoh/react-native-openharmony": "file:../react_native_openharmony",
    "@react-native-oh-tpl/react-native-clippath": "file:../../node_modules/@react-native-oh-tpl/react-native-clippath/harmony/clippath.har"
  }
```

点击右上角的 `sync` 按钮

或者在终端执行：

```bash
cd entry
ohpm install
```

方法二：直接链接源码

> [!TIP] 源码位于三方库安装路径的 `harmony` 文件夹下。

打开 `entry/oh-package.json5`，添加以下依赖

```json
"dependencies": {
"@rnoh/react-native-openharmony": "file:../react_native_openharmony",
"@react-native-oh-tpl/react-native-clippath": "file:../../node_modules/@react-native-oh-tpl/react-native-clippath/harmony/clippath"
}
```

打开终端，执行：

```bash
cd entry
ohpm install --no-link
```

### 配置 CMakeLists 和引入 ClipPathViewPackage.ClipPathViewNonePackage

打开 `entry/src/main/cpp/CMakeLists.txt`，添加：

```diff
project(rnapp)
cmake_minimum_required(VERSION 3.4.1)
set(RNOH_APP_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(OH_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../oh_modules")
set(RNOH_CPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../react-native-harmony/harmony/cpp")

add_subdirectory("${RNOH_CPP_DIR}" ./rn)

# RNOH_BEGIN: manual_package_linking_1
add_subdirectory("../../../../sample_package/src/main/cpp" ./sample-package)
+ add_subdirectory("${OH_MODULES}/@react-native-oh-tpl/react-native-clippath/src/main/cpp" ./clippath)
# RNOH_END: add_package_subdirectories

add_library(rnoh_app SHARED
    "./PackageProvider.cpp"
    "${RNOH_CPP_DIR}/RNOHAppNapiBridge.cpp"
)

target_link_libraries(rnoh_app PUBLIC rnoh)

# RNOH_BEGIN: link_packages
target_link_libraries(rnoh_app PUBLIC rnoh_sample_package)
+ target_link_libraries(rnoh_app PUBLIC rnoh_clip_path_view)
# RNOH_END: link_packages
```

打开 `entry/src/main/cpp/PackageProvider.cpp`，添加：

```diff
#include "RNOH/PackageProvider.h"
#include "SamplePackage.h"
+ #include "ClipPathViewPackage.h"
+ #include "ClipPathViewNonePackage.h"

using namespace rnoh;

std::vector<std::shared_ptr<Package>> PackageProvider::getPackages(Package::Context ctx) {
    return {
      std::make_shared<SamplePackage>(ctx),
+     std::make_shared<ClipPathViewPackage>(ctx),
+     std::make_shared<ClipPathViewNonePackage>(ctx)
    };
}
```

### 运行

点击右上角的 `sync` 按钮

或者在终端执行：

```bash
cd entry
ohpm install
```

然后编译、运行即可。

## 兼容性

要使用此库，需要使用正确的 React-Native 和 RNOH 版本。另外，还需要使用配套的 DevEco Studio 和 手机 ROM。

请到三方库相应的 Releases 发布地址查看 Release 配套的版本信息：[@react-native-oh-tpl/react-native-clippath Releases](https://github.com/react-native-oh-library/react-native-clippathreleases)

## API

> [!tip] "Platform"列表示该属性在原三方库上支持的平台。

> [!tip] "HarmonyOS Support"列为 yes 表示 HarmonyOS 平台支持该属性；no 则表示不支持；partially 表示部分支持。使用方法跨平台一致，效果对标 iOS 或 Android 的效果。  

| Name                 | Description                                                  | Type              | Required | Platform    | HarmonyOS Support |
| -------------------- | ------------------------------------------------------------ | ----------------- | -------- | ----------- |-------------------|
| d                    | 形状由一系列命令定义（svg path data）                        | string            | No       | IOS/Android | Yes               |
| viewBox              | 定义用户空间中的位置和维度                                   | Array<Number>(4)  | No       | IOS/Android | Yes               |
| align                | preserveAspectRatio 属性的 align                             | string            | No       | IOS/Android | Yes               |
| aspect               | preserveAspectRatio 属性的 meetOrSlice                       | meet/slice/none   | No       | IOS/Android | No                |
| fillRule             | 路径内部填充规则                                             | nonzero/evenodd   | No       | IOS/Android | No                |
| strokeWidth          | 路径描边宽度                                                 | number            | No       | IOS/Android | NO                |
| strokeCap            | 开放路径两端的形状                                           | butt/round/square | No       | IOS/Android | NO                |
| strokeJoin           | 路径转角处使用的形状                                         | bevel/miter/round | No       | IOS/Android | NO                |
| strokeMiter          | strokeJoin值是miter，设置夹角延伸                            | number            | No       | IOS/Android | NO                |
| strokeStart          | IOS CAShapeLayer 描线开始的地方占总路径的百分比。默认值是0。 | number            | No       | IOS/Android | No                |
| strokeEnd            | IOS CAShapeLayer 表示绘制结束的地方站总路径的百分比。默认值是1，如果小于等于strokeStart 则绘制不出任何内容。 | number            | No       | IOS/Android | No                |
| transX               | 在二维平面上水平方向移动元素                                 | number            | No       | IOS/Android | Yes               |
| transY               | 在二维平面上垂直方向移动元素                                 | number            | No       | IOS/Android | Yes               |
| transPercentageValue | transX、transY 使用百分比                                    | boolean           | No       | IOS/Android | Yes               |
| rot                  | 元素围绕一个定点旋转                                         | number            | No       | IOS/Android | Yes               |
| rotOx                | 旋转中心点水平位置                                           | number            | No       | IOS/Android | Yes               |
| rotOy                | 旋转中心点垂直位置                                           | number            | No       | IOS/Android | Yes               |
| rotPercentageValue   | rotOx、rotOy 使用百分比                                      | boolean           | No       | IOS/Android | Yes               |
| sc                   | 放大或缩小元素                                               | number            | No       | IOS/Android | Yes               |
| scX                  | 水平缩放                                                     | number            | No       | IOS/Android | Yes               |
| scY                  | 垂直缩放                                                     | number            | No       | IOS/Android | Yes               |
| scO                  | 缩放中心点位置                                               | number            | No       | IOS/Android | Yes               |
| scOx                 | 缩放中心点水平位置                                           | number            | No       | IOS/Android | Yes               |
| scOy                 | 缩放中心点垂直位置                                           | number            | No       | IOS/Android | Yes               |
| scPercentageValue    | scO、scOx、scOy使用百分比                                    | boolean           | No       | IOS/Android | Yes               |

## 遗留问题

## 其他

## 开源协议

本项目基于 [The MIT License (MIT)](https://github.com/Only-IceSoul/react-native-clippath/blob/main/LICENSE) ，请自由地享受和参与开源。
