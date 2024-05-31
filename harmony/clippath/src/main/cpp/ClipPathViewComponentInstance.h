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

#ifndef HARMONY_CLIPPATHVIEWCOMPONENTINSTANCE_H
#define HARMONY_CLIPPATHVIEWCOMPONENTINSTANCE_H

#include "RNOH/CppComponentInstance.h"
#include "ClipPathViewStackNode.h"
#include "Props.h"
#include "ShadowNodes.h"

namespace rnoh {
    class ClipPathViewComponentInstance : public CppComponentInstance<facebook::react::RNCClipPathViewShadowNode>{
    private:
        ClipPathViewStackNode m_stackNode;
        std::string d;
        float opacity = 1.0f;
        bool opacityStatus = false;
        std::string aspect ;
//         std::string mask = "/0";
//         std::string oldMask = "/0";
//         int fillColor = 0x000000;
//         bool fillColorStatus = false;
//         float fillOpacity = 1.0f;
//         bool fillOpacityStatus = false;
        std::string fillRule = "/0";
//         bool fillRuleStatus = false;
        int strokeColor;
        bool strokeColorStatus;
        float strokeOpacity;
        bool strokeOpacityStatus;
        float strokeWidth;
        bool strokeWidthStatus;
        std::string strokeCap;
        std::string strokeJoin;
        float strokeMiter;
        bool strokeMiterStatus;
        float strokeStart;
        bool strokeStartStatus;
        float strokeEnd;
        bool strokeEndStatus;
//         int shadowColor;
//         bool shadowColorStatus;
//         float shadowOpacity ;
//         bool shadowOpacityStatus;
//         float shadowRadius;
//         bool shadowRadiusStatus;
//         float shadowOffsetX;
//         float shadowOffsetY;
//         bool shadowOffsetIsPercent;
//         bool shadowOffsetStatus;
    
        float transX = 0.f;
        float transY = 0.f;
        bool transPercentageValue = false;
        float rot;
        float rotO;
        float rotOx;
        float rotOy;
        bool rotPercentageValue;
        float sc = 1.f;
        float scX = 1.f;
        float scY = 1.f;
        float scO = 0.f;
        float scOx = 0.f;
        float scOy = 0.f;
        bool scPercentageValue = false;
        std::string align;
        std::vector<float> viewBox{};
        int bgColor{0x00000000};

    public:
        ClipPathViewComponentInstance(Context context);
        void onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) override;

        void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override;
        ClipPathViewStackNode &getLocalRootArkUINode() override;
        void onPropsChanged(SharedConcreteProps const &props) override;
        void getNapiProps(facebook::react::Props::Shared props);
    };
} // namespace rnoh

#endif // HARMONY_CLIPPATHVIEWCOMPONENTINSTANCE_H
