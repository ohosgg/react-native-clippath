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
#pragma once

#include "RNOH/arkui/ArkUINode.h"
#include "RNOH/arkui/StackNode.h"
#include <react/renderer/graphics/Color.h>
#include "RectF.h"
#include "ModUtil.h"
#include <../../Transform.h>

namespace rnoh {
    class Display {
    public:
        float density;

        Display(float density) : density(density) {}
    };

    class TypedValue {
    public:
        static float applyDimension(int unit, float value, const Display &metrics) {
            if (unit == COMPLEX_UNIT_DIP) {
                return value * metrics.density;
            } else {
                return value;
            }
        }

        static const int COMPLEX_UNIT_DIP = 1; 
    };


    class ClipPathViewStackNode : public ArkUINode {
    public:
        ClipPathViewStackNode();

        void insertChild(ArkUINode &child, std::size_t index);
        void removeChild(ArkUINode &child);
        void setD(const std::string d);
        void setOpacity(const float opacity);
        void setAspect(const std::string aspect);
        //         void setMask(const std::string mask);
        //
        //         void setOldMask(const std::string oldMask);

        //         void setFillColor(int const &);

        //         void setFillOpacity(const float &);

        void setFillRule(const std::string rule);

        void setStrokeColor(int const color);

        void setStrokeOpacity(float const strokeOpacity);

        void setStrokeWidth(float const width);

        void setStrokeCap(std::string const cap);

        void setStrokeJoin(std::string const &);

        void setStrokeMiter(float const &);

        void setStrokeStart(float const &);

        void setStrokeEnd(float const &);

        void setShadowColor(int const &);

        void setShadowOpacity(float const &);

        void setShadowRadius(float const &);

        void setShadowOffsetX(float const &);

        void setShadowOffsetY(float const &);

        void setShadowOffsetIsPercent(bool const &);
        void setBgColor(int const &);


        facebook::react::Transform transformScale;
        rnoh::RectF rectF;
        rnoh::RectF rectFVb, rectFVbDensity;
        rnoh::ModUtil modUtil;

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
        int bgColor{0x00000000};

        std::string align{"xMidYMid"};
        std::vector<float> viewBox{};

        //         float shadowRadius;
        //         float shadowOffsetX;
        //         float shadowOffsetY;
        //         uint32_t shadowColor;

        void transform();
        bool validateViewBox();
        float toDip(float value);
        void setSc(float v);
        void setScX(float v);
        void setScY(float v);
        void setScO(float v);
        void setScOx(float v);
        void setScOy(float v);
        void setScPercentageValue(bool v);
        void setTransX(float v);
        void setTransY(float v);
        void setTransPercentageValue(bool v);
        void setRot(float v);
        void setRotO(float v);
        void setRotOx(float v);
        void setRotOy(float v);
        void setRotPercentageValue(bool v);

        void setAlign(std::string align);
        void setViewBox(const std::vector<float> &);
private:
        float getDensity();
    };
} // namespace rnoh