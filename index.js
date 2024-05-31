
import { Platform } from "react-native";
//import ClipPathViewIos from "./src/ClipPath.ios.js";
import ClipPathViewNoneAndroid from "./src/ClipPath.android.js";
//import ClipPathViewWeb from "./src/ClipPath.web.js";
export const ClipPathView  = ClipPathViewNoneAndroid;

import ClipPathViewAndroid from "./src/ClipPath.android.js";
//import ClipPathViewWeb from "./src/ClipPath.web.js";
export const ClipPathViewH  = ClipPathViewAndroid;
/*
export const ClipPathView = Platform.OS === "ios"
  ? ClipPathViewIos : Platform.OS === "android"
  ? ClipPathViewAndroid : ClipPathViewWeb;

import ClipPathViewHIos from "./src/ClipPathH.ios.js";
import ClipPathViewHAndroid from "./src/ClipPathH.android.js";
import ClipPathViewHWeb from "./src/ClipPathH.web.js";

export const ClipPathViewH = Platform.OS === "ios"
  ? ClipPathViewHIos : Platform.OS === "android"
  ? ClipPathViewHAndroid : ClipPathViewHWeb;
*/