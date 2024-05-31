/*
 * Copyright (C) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Props.h"
#include <react/renderer/core/PropsParserContext.h>
#include <react/renderer/core/propsConversions.h>

namespace facebook {
    namespace react {

        RNCClipPathViewProps::RNCClipPathViewProps(const PropsParserContext &context,
                                                   const RNCClipPathViewProps &sourceProps, const RawProps &rawProps)
            : ViewProps(context, sourceProps, rawProps),
              opacity(convertRawProp(context, rawProps, "opacity", sourceProps.opacity, 1.0f)),
              d(convertRawProp(context, rawProps, "d", sourceProps.d, "/0")),
              opacityStatus(convertRawProp(context, rawProps, "opacityStatus", sourceProps.opacityStatus, false)),
              aspect(convertRawProp(context, rawProps, "aspect", sourceProps.aspect, "meet")),
              //               mask(convertRawProp(context, rawProps, "mask", sourceProps.mask, "/0")),
              //               oldMask(convertRawProp(context, rawProps, "oldMask", sourceProps.oldMask, "/0")),
              //               fillColor(convertRawProp(context, rawProps, "fillColor", sourceProps.fillColor,
              //               {0x000000})), fillColorStatus(convertRawProp(context, rawProps, "fillColorStatus",
              //               sourceProps.fillColorStatus, false)), fillOpacity(convertRawProp(context, rawProps,
              //               "fillOpacity", sourceProps.fillOpacity, 1.0f)), fillOpacityStatus(
              //                   convertRawProp(context, rawProps, "fillOpacityStatus", sourceProps.fillOpacityStatus,
              //                   false)),
              fillRule(convertRawProp(context, rawProps, "fillRule", sourceProps.fillRule, "/0")),
              //               fillRuleStatus(convertRawProp(context, rawProps, "fillRuleStatus",
              //               sourceProps.fillRuleStatus, false)),

              strokeColor(convertRawProp(context, rawProps, "strokeColor", sourceProps.strokeColor, {0x00000000})),
              strokeColorStatus(
                  convertRawProp(context, rawProps, "strokeColorStatus", sourceProps.strokeColorStatus, {false})),
              strokeOpacity(convertRawProp(context, rawProps, "strokeOpacity", sourceProps.strokeOpacity, {1.0})),
              strokeOpacityStatus(
                  convertRawProp(context, rawProps, "strokeOpacityStatus", sourceProps.strokeOpacityStatus, {false})),
              strokeWidth(convertRawProp(context, rawProps, "strokeWidth", sourceProps.strokeWidth, {1.0})),
              strokeWidthStatus(
                  convertRawProp(context, rawProps, "strokeWidthStatus", sourceProps.strokeWidthStatus, {false})),
              strokeCap(convertRawProp(context, rawProps, "strokeCap", sourceProps.strokeCap, {"none"})),
              strokeJoin(convertRawProp(context, rawProps, "strokeJoin", sourceProps.strokeJoin, {"none"})),
              strokeMiter(convertRawProp(context, rawProps, "strokeMiter", sourceProps.strokeMiter, {4.0})),
              strokeMiterStatus(
                  convertRawProp(context, rawProps, "strokeMiterStatus", sourceProps.strokeMiterStatus, {false})),
              strokeStart(convertRawProp(context, rawProps, "strokeStart", sourceProps.strokeStart, {0.0})),
              strokeStartStatus(
                  convertRawProp(context, rawProps, "strokeStartStatus", sourceProps.strokeStartStatus, {false})),
              strokeEnd(convertRawProp(context, rawProps, "strokeEnd", sourceProps.strokeEnd, {1.0})),
              strokeEndStatus(
                  convertRawProp(context, rawProps, "strokeEndStatus", sourceProps.strokeEndStatus, {false})),

              //               shadowColor(convertRawProp(context, rawProps, "shadowColor", sourceProps.shadowColor,
              //               {0x000000})), shadowColorStatus(
              //                   convertRawProp(context, rawProps, "shadowColorStatus", sourceProps.shadowColorStatus,
              //                   {false})),
              //               shadowOpacity(convertRawProp(context, rawProps, "shadowOpacity",
              //               sourceProps.shadowOpacity, {0.0})), shadowOpacityStatus(
              //                   convertRawProp(context, rawProps, "shadowOpacityStatus",
              //                   sourceProps.shadowOpacityStatus, {false})),
              //               shadowRadius(convertRawProp(context, rawProps, "shadowRadius", sourceProps.shadowRadius,
              //               {2.0})), shadowRadiusStatus(
              //                   convertRawProp(context, rawProps, "shadowRadiusStatus",
              //                   sourceProps.shadowRadiusStatus, {false})),
              //               shadowOffsetX(convertRawProp(context, rawProps, "shadowOffsetX",
              //               sourceProps.shadowOffsetX, {2.0})), shadowOffsetY(convertRawProp(context, rawProps,
              //               "shadowOffsetY", sourceProps.shadowOffsetY, {2.0})),
              //               shadowOffsetIsPercent(convertRawProp(context, rawProps, "shadowOffsetIsPercent",
              //                                                    sourceProps.shadowOffsetIsPercent, {false})),
              //               shadowOffsetStatus(
              //                   convertRawProp(context, rawProps, "shadowOffsetStatus",
              //                   sourceProps.shadowOffsetStatus, {false})),

              transX(convertRawProp(context, rawProps, "transX", sourceProps.transX, {0.0})),
              transY(convertRawProp(context, rawProps, "transY", sourceProps.transY, {0.0})),
              transPercentageValue(
                  convertRawProp(context, rawProps, "transPercentageValue", sourceProps.transPercentageValue, {false})),
              rot(convertRawProp(context, rawProps, "rot", sourceProps.rot, {0.0})),
              rotO(convertRawProp(context, rawProps, "rotO", sourceProps.rotO, {0.0})),
              rotOx(convertRawProp(context, rawProps, "rotOx", sourceProps.rotOx, {0.0})),
              rotOy(convertRawProp(context, rawProps, "rotOy", sourceProps.rotOy, {0.0})),
              rotPercentageValue(
                  convertRawProp(context, rawProps, "rotPercentageValue", sourceProps.rotPercentageValue, {false})),
              sc(convertRawProp(context, rawProps, "sc", sourceProps.sc, {1.0})),
              scX(convertRawProp(context, rawProps, "scX", sourceProps.scX, {1.0})),
              scY(convertRawProp(context, rawProps, "scY", sourceProps.scY, {1.0})),
              scO(convertRawProp(context, rawProps, "scO", sourceProps.scO, {0.0})),
              scOx(convertRawProp(context, rawProps, "scOX", sourceProps.scOx, {0.0})),
              scOy(convertRawProp(context, rawProps, "scOY", sourceProps.scOy, {0.0})),
              scPercentageValue(
                  convertRawProp(context, rawProps, "scPercentageValue", sourceProps.scPercentageValue, {false})),
              bgColor(convertRawProp(context, rawProps, "bgColor", sourceProps.bgColor, {0x00000000})),
              align(convertRawProp(context, rawProps, "align", sourceProps.align, {"xMidYMid"})),
              viewBox(convertRawProp(context, rawProps, "viewBox", sourceProps.viewBox, {})) {}
        RNCClipPathViewNoneProps::RNCClipPathViewNoneProps(const PropsParserContext &context,
                                                           const RNCClipPathViewNoneProps &sourceProps,
                                                           const RawProps &rawProps)
            : ViewProps(context, sourceProps, rawProps),
              opacity(convertRawProp(context, rawProps, "opacity", sourceProps.opacity, 1.0f)),
              d(convertRawProp(context, rawProps, "d", sourceProps.d, "/0")),
              opacityStatus(convertRawProp(context, rawProps, "opacityStatus", sourceProps.opacityStatus, false)),
              aspect(convertRawProp(context, rawProps, "aspect", sourceProps.aspect, "meet")),
              //               mask(convertRawProp(context, rawProps, "mask", sourceProps.mask, "/0")),
              //               oldMask(convertRawProp(context, rawProps, "oldMask", sourceProps.oldMask, "/0")),
              //               fillColor(convertRawProp(context, rawProps, "fillColor", sourceProps.fillColor,
              //               {0x000000})), fillColorStatus(convertRawProp(context, rawProps, "fillColorStatus",
              //               sourceProps.fillColorStatus, false)), fillOpacity(convertRawProp(context, rawProps,
              //               "fillOpacity", sourceProps.fillOpacity, 1.0f)), fillOpacityStatus(
              //                   convertRawProp(context, rawProps, "fillOpacityStatus", sourceProps.fillOpacityStatus,
              //                   false)),
              fillRule(convertRawProp(context, rawProps, "fillRule", sourceProps.fillRule, "/0")),
              //               fillRuleStatus(convertRawProp(context, rawProps, "fillRuleStatus",
              //               sourceProps.fillRuleStatus, false)),

              strokeColor(convertRawProp(context, rawProps, "strokeColor", sourceProps.strokeColor, {0x00000000})),
              strokeColorStatus(
                  convertRawProp(context, rawProps, "strokeColorStatus", sourceProps.strokeColorStatus, {false})),
              strokeOpacity(convertRawProp(context, rawProps, "strokeOpacity", sourceProps.strokeOpacity, {1.0})),
              strokeOpacityStatus(
                  convertRawProp(context, rawProps, "strokeOpacityStatus", sourceProps.strokeOpacityStatus, {false})),
              strokeWidth(convertRawProp(context, rawProps, "strokeWidth", sourceProps.strokeWidth, {1.0})),
              strokeWidthStatus(
                  convertRawProp(context, rawProps, "strokeWidthStatus", sourceProps.strokeWidthStatus, {false})),
              strokeCap(convertRawProp(context, rawProps, "strokeCap", sourceProps.strokeCap, {"none"})),
              strokeJoin(convertRawProp(context, rawProps, "strokeJoin", sourceProps.strokeJoin, {"none"})),
              strokeMiter(convertRawProp(context, rawProps, "strokeMiter", sourceProps.strokeMiter, {4.0})),
              strokeMiterStatus(
                  convertRawProp(context, rawProps, "strokeMiterStatus", sourceProps.strokeMiterStatus, {false})),
              strokeStart(convertRawProp(context, rawProps, "strokeStart", sourceProps.strokeStart, {0.0})),
              strokeStartStatus(
                  convertRawProp(context, rawProps, "strokeStartStatus", sourceProps.strokeStartStatus, {false})),
              strokeEnd(convertRawProp(context, rawProps, "strokeEnd", sourceProps.strokeEnd, {1.0})),
              strokeEndStatus(
                  convertRawProp(context, rawProps, "strokeEndStatus", sourceProps.strokeEndStatus, {false})),

              //               shadowColor(convertRawProp(context, rawProps, "shadowColor", sourceProps.shadowColor,
              //               {0x000000})), shadowColorStatus(
              //                   convertRawProp(context, rawProps, "shadowColorStatus", sourceProps.shadowColorStatus,
              //                   {false})),
              //               shadowOpacity(convertRawProp(context, rawProps, "shadowOpacity",
              //               sourceProps.shadowOpacity, {0.0})), shadowOpacityStatus(
              //                   convertRawProp(context, rawProps, "shadowOpacityStatus",
              //                   sourceProps.shadowOpacityStatus, {false})),
              //               shadowRadius(convertRawProp(context, rawProps, "shadowRadius", sourceProps.shadowRadius,
              //               {2.0})), shadowRadiusStatus(
              //                   convertRawProp(context, rawProps, "shadowRadiusStatus",
              //                   sourceProps.shadowRadiusStatus, {false})),
              //               shadowOffsetX(convertRawProp(context, rawProps, "shadowOffsetX",
              //               sourceProps.shadowOffsetX, {2.0})), shadowOffsetY(convertRawProp(context, rawProps,
              //               "shadowOffsetY", sourceProps.shadowOffsetY, {2.0})),
              //               shadowOffsetIsPercent(convertRawProp(context, rawProps, "shadowOffsetIsPercent",
              //                                                    sourceProps.shadowOffsetIsPercent, {false})),
              //               shadowOffsetStatus(
              //                   convertRawProp(context, rawProps, "shadowOffsetStatus",
              //                   sourceProps.shadowOffsetStatus, {false})),

              transX(convertRawProp(context, rawProps, "transX", sourceProps.transX, {0.0})),
              transY(convertRawProp(context, rawProps, "transY", sourceProps.transY, {0.0})),
              transPercentageValue(
                  convertRawProp(context, rawProps, "transPercentageValue", sourceProps.transPercentageValue, {false})),
              rot(convertRawProp(context, rawProps, "rot", sourceProps.rot, {0.0})),
              rotO(convertRawProp(context, rawProps, "rotO", sourceProps.rotO, {0.0})),
              rotOx(convertRawProp(context, rawProps, "rotOx", sourceProps.rotOx, {0.0})),
              rotOy(convertRawProp(context, rawProps, "rotOy", sourceProps.rotOy, {0.0})),
              rotPercentageValue(
                  convertRawProp(context, rawProps, "rotPercentageValue", sourceProps.rotPercentageValue, {false})),
              sc(convertRawProp(context, rawProps, "sc", sourceProps.sc, {1.0})),
              scX(convertRawProp(context, rawProps, "scX", sourceProps.scX, {1.0})),
              scY(convertRawProp(context, rawProps, "scY", sourceProps.scY, {1.0})),
              scO(convertRawProp(context, rawProps, "scO", sourceProps.scO, {0.0})),
              scOx(convertRawProp(context, rawProps, "scOX", sourceProps.scOx, {0.0})),
              scOy(convertRawProp(context, rawProps, "scOY", sourceProps.scOy, {0.0})),
              scPercentageValue(
                  convertRawProp(context, rawProps, "scPercentageValue", sourceProps.scPercentageValue, {false})),

              align(convertRawProp(context, rawProps, "align", sourceProps.align, {"xMidYMid"})),
              viewBox(convertRawProp(context, rawProps, "viewBox", sourceProps.viewBox, {})){}
    } // namespace react
} // namespace facebook