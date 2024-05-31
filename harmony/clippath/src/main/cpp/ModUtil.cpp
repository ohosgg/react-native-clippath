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

#include "ModUtil.h"
#include "RectF.h"


     float rnoh::ModUtil::clamp(float v) { return v > 1 ? 1 : (v < 0 ? 0 : v); }

     float rnoh::ModUtil::uClamp(float v) { return v < 0 ? 0 : v; }


     float rnoh::ModUtil::uClamp(float v, float optional) { return v < 0 ? optional : v; }


     float rnoh::ModUtil::viewBoxEvaluator(float value, float start, float end) { return (value - start) / (end - start); }

     float rnoh::ModUtil::viewBoxToWidth(float value, rnoh::RectF rectF, float w) {
        return viewBoxEvaluator(value, rectF.left, rectF.right) * w;
    }

     float rnoh::ModUtil::viewBoxToHeight(float value, rnoh::RectF rectF, float h) {
        return viewBoxEvaluator(value, rectF.top, rectF.bottom) * h;
    }


     float rnoh::ModUtil::viewBoxToMax(float value, rnoh::RectF rectF, float w, float h) {
        float size = rectF.width() >rectF.height()?rectF.width():rectF.height();
        float maxVb = w > h ? rectF.width() : rectF.height();
        return (value / maxVb) * size;
    }

