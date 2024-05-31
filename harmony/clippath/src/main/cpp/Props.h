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

#ifndef HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_PROPS_H
#define HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_PROPS_H

#include <jsi/jsi.h>
#include <react/renderer/components/view/ViewProps.h>
#include <react/renderer/core/PropsParserContext.h>
#include <react/renderer/core/propsConversions.h>

#include <vector>
#include <boost/json.hpp>
namespace facebook {
    namespace react {


        class JSI_EXPORT RNCClipPathViewProps final : public ViewProps {
        public:
            RNCClipPathViewProps() = default;
            RNCClipPathViewProps(const PropsParserContext &context, const RNCClipPathViewProps &sourceProps,
                                 const RawProps &rawProps);

#pragma mark - Props
            std::string d;
            float opacity = 1.0f;
            bool opacityStatus = false;
            std::string aspect;
//             std::string mask = "/0";
//             std::string oldMask = "/0";
//             int fillColor = 0x000000;
//             bool fillColorStatus = false;
//             float fillOpacity = 1.0f;
//             bool fillOpacityStatus = false;
            std::string fillRule = "/0";
//             bool fillRuleStatus = false;
            int strokeColor{0x00000000};
            bool strokeColorStatus{false};
            float strokeOpacity{1.0};
            bool strokeOpacityStatus{false};
            float strokeWidth{1.0};
            bool strokeWidthStatus{false};
            std::string strokeCap{"none"};
            std::string strokeJoin{"none"};
            float strokeMiter{4.0};
            bool strokeMiterStatus{false};
            float strokeStart{0.0};
            bool strokeStartStatus{false};
            float strokeEnd{1.0};
            bool strokeEndStatus{false};
//             int shadowColor{0x000000};
//             bool shadowColorStatus{false};
//             float shadowOpacity{0.0};
//             bool shadowOpacityStatus{false};
//             float shadowRadius{2.0};
//             bool shadowRadiusStatus{false};
//             float shadowOffsetX{2.0};
//             float shadowOffsetY{2.0};
//             bool shadowOffsetIsPercent{false};
//             bool shadowOffsetStatus{false};

            float transX = 0.f;
            float transY = 0.f;
            bool transPercentageValue = false;
            float rot = 0.f;
            float rotO = 0.f;
            float rotOx = 0.f;
            float rotOy = 0.f;
            bool rotPercentageValue = false;
            float sc = 1.f;
            float scX = 1.f;
            float scY = 1.f;
            float scO = 0.f;
            float scOx = 0.f;
            float scOy = 0.f;
            bool scPercentageValue = false;
            std::string align{"xMidYMid"};
            int bgColor{0x00000000};
            std::vector<float> viewBox{};
        };

        class JSI_EXPORT RNCClipPathViewNoneProps final : public ViewProps {
        public:
            RNCClipPathViewNoneProps() = default;
            RNCClipPathViewNoneProps(const PropsParserContext &context, const RNCClipPathViewNoneProps &sourceProps,
                                     const RawProps &rawProps);

#pragma mark - Props
            std::string d;
            float opacity = 1.0f;
            bool opacityStatus = false;
            std::string aspect;
            //             std::string mask = "/0";
            //             std::string oldMask = "/0";
            //             int fillColor = 0x000000;
            //             bool fillColorStatus = false;
            //             float fillOpacity = 1.0f;
            //             bool fillOpacityStatus = false;
            std::string fillRule = "/0";
            //             bool fillRuleStatus = false;
            int strokeColor{0x00000000};
            bool strokeColorStatus{false};
            float strokeOpacity{1.0};
            bool strokeOpacityStatus{false};
            float strokeWidth{1.0};
            bool strokeWidthStatus{false};
            std::string strokeCap{"none"};
            std::string strokeJoin{"none"};
            float strokeMiter{4.0};
            bool strokeMiterStatus{false};
            float strokeStart{0.0};
            bool strokeStartStatus{false};
            float strokeEnd{1.0};
            bool strokeEndStatus{false};
            //             int shadowColor{0x000000};
            //             bool shadowColorStatus{false};
            //             float shadowOpacity{0.0};
            //             bool shadowOpacityStatus{false};
            //             float shadowRadius{2.0};
            //             bool shadowRadiusStatus{false};
            //             float shadowOffsetX{2.0};
            //             float shadowOffsetY{2.0};
            //             bool shadowOffsetIsPercent{false};
            //             bool shadowOffsetStatus{false};

            float transX = 0.f;
            float transY = 0.f;
            bool transPercentageValue = false;
            float rot = 0.f;
            float rotO = 0.f;
            float rotOx = 0.f;
            float rotOy = 0.f;
            bool rotPercentageValue = false;
            float sc = 1.f;
            float scX = 1.f;
            float scY = 1.f;
            float scO = 0.f;
            float scOx = 0.f;
            float scOy = 0.f;
            bool scPercentageValue = false;
            std::vector<float> viewBox{};

            std::string align{"xMidYMid"};
        };

    } // namespace react
} // namespace facebook
#endif
