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

#ifndef HARMONY_SVGPATHPARSER_H
#define HARMONY_SVGPATHPARSER_H
#include <string>
#include "RectF.h"
#include "Point.h"

namespace rnoh {
    class SVGPathParser {
    public:
        static float mScale;
        static float mX;
        static float mY;
        static std::vector<Point> mPoints;
        static RectF mArcRect;
        static void parse(const std::string d);
    private:
        static int i;
        static int l;
        static std::string s;
        static float mPenX;
        static float mPenY;
        static float mPivotX;
        static float mPivotY;
        static float mPenDownX;
        static float mPenDownY;
        static bool mPenDown;
        static void move(float x, float y);
        static void moveTo(float x, float y);
        static void line(float x, float y);
        static void lineTo(float x, float y);
        static void arc(float rx, float ry, float rotation, bool outer, bool clockwise, float x, float y);
        static void arcTo(float rx, float ry, float rotation, bool outer, bool clockwise, float x, float y);
        static void setPenDown();
        static double _round(double val);
        static void skip_spaces();
        static bool is_cmd(char c);
        static bool is_number_start(char c);
        static bool is_absolute(char c);
        static bool parse_flag();
        static float parse_list_number();
        static float parse_number();
        static void parse_list_separator();
        static void skip_digits();
        static void close();
    };
} // namespace rnoh
#endif // HARMONY_SVGPATHPARSER_H
