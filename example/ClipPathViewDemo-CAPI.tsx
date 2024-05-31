/*
 * @Author: 17682309129 song_yu@hoperun.com
 * @Date: 2024-04-19 14:54:53
 * @LastEditors: 17682309129 song_yu@hoperun.com
 * @LastEditTime: 2024-05-16 14:54:23
 * @FilePath: \AwesomeProjectf:\ets\react\canal\clippath\rn-project\daima\liangtao\clippath\third_part_demo\ClipPathViewDemo-CAPI.tsx
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

import {View, StyleSheet,Image,Dimensions, ScrollView,Text} from 'react-native';
import {ClipPathView} from '@react-native-oh-tpl/react-native-clippath';
import { Colors } from 'react-native/Libraries/NewAppScreen';

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
