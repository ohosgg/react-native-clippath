# clippath单元测试用例

该测试用例基于HarmonyOS系统下，采用[原库测试用例](https://gitee.com/harmonyOS_tony/harmony/blob/master/ClipPathViewDemo-CAPI.tsx)
进行单元测试

单元测试用例覆盖情况

## Props

| Name | description | type | default |
| --- | --- | --- | --- |
| d | The shape, defined by a series of commands   | String | "" |
| viewBox | defines the position and dimension, in user space    | Array[Number] (4) | undefined |
| align | the aligment     | String | xMidYMid |
| aspect | aspect ratio   | String | meet |
| fillRule | determines what side of a path is inside a shape  | String | nonzero |
| strokeWidth | defines the thickness of a line (mobile) | Number | 1 
| strokeCap | line cap  (mobile) | string | 'butt' |
| strokeJoin | line join  (mobile) | string | 'miter' |
| strokeMiter | control the behavior of miter (mobile) | Number | 4 |
| strokeStart | the start  (mobile) | Number | 0 |
| strokeEnd | the end  (mobile) | Number | 1 |

<br>

### Transform ###  

<br>

The percentageValue property refers to the fact that the Origin will be multiplied by the size of the view.

| Name | type | default |
| --- | --- | --- |
| translateZ | Number (zIndex) | 0 |
| transX | Number | 0 |
| transY | Number | 0 |
| transPercentageValue | Bool | false |
| rot | Number | 0 |
| rotOx | Number | 0 |
| rotOy | Number | 0 |
| rotPercentageValue | Bool | false |
| sc | Number | 1 |
| scX | Number | 1 |
| scY | Number | 1 |
| scO | Number | 0 |
| scOx | Number | 0 |
| scOy | Number | 0 |
| scPercentageValue | Bool | false |