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
#ifndef HARMONY_MODUTIL_H
#define HARMONY_MODUTIL_H
#include "RectF.h"
namespace rnoh {
   class ModUtil{
    public:
        static float clamp(float v);
        static float uClamp(float v);
        static float uClamp(float v, float optional);
        static float viewBoxEvaluator(float value, float start, float end);
        static float viewBoxToWidth(float value, rnoh::RectF rectF, float w);
        static float viewBoxToHeight(float value, rnoh::RectF rectF, float h);
        static float viewBoxToMax(float value, rnoh::RectF rectF, float w, float h);
   };

};
#endif //HARMONY_MODUTIL_H
