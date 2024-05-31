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

#include "SVGPathParser.h"
#include <stdexcept>
#include <sstream>
#include "math.h"
#include <cctype>
#include "cmath"
#include "RectF.h"
#include "Point.h"
#include "vector"


namespace rnoh {
    float SVGPathParser::mScale = 2.5f;
    float SVGPathParser::mX = 0.f;
    float SVGPathParser::mY = 0.f;
    std::vector<Point>  SVGPathParser::mPoints = std::vector<Point>();
    RectF SVGPathParser::mArcRect = RectF();
    int SVGPathParser::i = 0;
    int SVGPathParser::l = 0;
    std::string SVGPathParser::s = "";
    float SVGPathParser::mPenX = 0.0f;
    float SVGPathParser::mPenY = 0.0f;
    float SVGPathParser::mPivotX = 0.0f;
    float SVGPathParser::mPivotY = 0.0f;
    float SVGPathParser::mPenDownX = 0.0f;
    float SVGPathParser::mPenDownY = 0.0f;
    bool SVGPathParser::mPenDown = false;

    void SVGPathParser::parse(const std::string d) {
        if (d.empty()) {
            return;
        }
        char prev_cmd = ' ';
        l = d.length();
        s = d;
        i = 0;

        mPenX = 0.f;
        mPenY = 0.f;
        mPivotX = 0.f;
        mPivotY = 0.f;
        mPenDownX = 0.f;
        mPenDownY = 0.f;
        mPenDown = false;

        while (i < l) {
            skip_spaces();

            if (i >= l) {
                break;
            }

            bool has_prev_cmd = prev_cmd != ' ';
            char first_char = s.at(i);

            if (!has_prev_cmd && first_char != 'M' && first_char != 'm') {
                // The first segment must be a MoveTo.
                std::ostringstream oss;
                oss << "Unexpected character" << first_char << ",i=" << i << ",s=" << s;
                throw std::logic_error(oss.str());
            }

            // TODO: simplify
            bool is_implicit_move_to;
            char cmd;
            if (is_cmd(first_char)) {
                is_implicit_move_to = false;
                cmd = first_char;
                i += 1;
            } else if (is_number_start(first_char) && has_prev_cmd) {
                if (prev_cmd == 'Z' || prev_cmd == 'z') {
                    // ClosePath cannot be followed by a number.
                    std::ostringstream oss;
                    oss << "Unexpected number after 'z' (s=" << s << ")";
                    throw std::logic_error(oss.str());
                }

                if (prev_cmd == 'M' || prev_cmd == 'm') {
                    // 'If a moveto is followed by multiple pairs of coordinates,
                    // the subsequent pairs are treated as implicit lineto commands.'
                    // So we parse them as LineTo.
                    is_implicit_move_to = true;
                    if (is_absolute(prev_cmd)) {
                        cmd = 'L';
                    } else {
                        cmd = 'l';
                    }
                } else {
                    is_implicit_move_to = false;
                    cmd = prev_cmd;
                }
            } else {
                std::ostringstream oss;
                oss << "Unexpected character" << first_char << ",i=" << i << ",s=" << s;
                throw std::logic_error(oss.str());
            }

            bool absolute = is_absolute(cmd);
            switch (cmd) {
            case 'm': {
            rnoh:
                SVGPathParser::move(parse_list_number(), parse_list_number());
                break;
            }
            case 'M': {
                moveTo(parse_list_number(), parse_list_number());
                break;
            }
            case 'l': {
                line(parse_list_number(), parse_list_number());
                break;
            }
            case 'L': {
                lineTo(parse_list_number(), parse_list_number());
                break;
            }
            case 'h': {
                line(parse_list_number(), 0);
                break;
            }
            case 'H': {
                lineTo(parse_list_number(), mPenY);
                break;
            }
            case 'v': {
                line(0, parse_list_number());
                break;
            }
            case 'V': {
                lineTo(mPenX, parse_list_number());
                break;
            }
            case 'c': {
                //             curve(parse_list_number(), parse_list_number(), parse_list_number(), parse_list_number(),
                //                   parse_list_number(), parse_list_number());
                break;
            }
            case 'C': {
                //             curveTo(parse_list_number(), parse_list_number(), parse_list_number(),
                //             parse_list_number(),
                //                     parse_list_number(), parse_list_number());
                break;
            }
            case 's': {
                //             smoothCurve(parse_list_number(), parse_list_number(), parse_list_number(),
                //             parse_list_number());
                break;
            }
            case 'S': {
                //             smoothCurveTo(parse_list_number(), parse_list_number(), parse_list_number(),
                //             parse_list_number());
                break;
            }
            case 'q': {
                //             quadraticBezierCurve(parse_list_number(), parse_list_number(), parse_list_number(),
                //             parse_list_number());
                break;
            }
            case 'Q': {
                //             quadraticBezierCurveTo(parse_list_number(), parse_list_number(), parse_list_number(),
                //             parse_list_number());
                break;
            }
            case 't': {
                //             smoothQuadraticBezierCurve(parse_list_number(), parse_list_number());
                break;
            }
            case 'T': {
                //             smoothQuadraticBezierCurveTo(parse_list_number(), parse_list_number());
                break;
            }
            case 'a': {
                arc(parse_list_number(), parse_list_number(), parse_list_number(), parse_flag(), parse_flag(),
                    parse_list_number(), parse_list_number());
                break;
            }
            case 'A': {
                arcTo(parse_list_number(), parse_list_number(), parse_list_number(), parse_flag(), parse_flag(),
                      parse_list_number(), parse_list_number());
                break;
            }
            case 'z':
            case 'Z': {
                close();
                break;
            }
            default: {
                std::ostringstream oss;
                oss << "Unexpected comand " << cmd << ",s=" << s << ")";
                throw std::logic_error(oss.str());
            }
            }

            if (is_implicit_move_to) {
                if (absolute) {
                    prev_cmd = 'M';
                } else {
                    prev_cmd = 'm';
                }
            } else {
                prev_cmd = cmd;
            }
        }
    }


    void SVGPathParser::move(float x, float y) { moveTo(x + mPenX, y + mPenY); }

    void SVGPathParser::moveTo(float x, float y) {
        // FLog.w(ReactConstants.TAG, "move x: " + x + " y: " + y);
        mPenDownX = mPivotX = mPenX = x;
        mPenDownY = mPivotY = mPenY = y;
        mX = x * mScale;
        mY = y * mScale;
        //     mPath.moveTo(x * mScale, y * mScale);
    }

    void SVGPathParser::line(float x, float y) { lineTo(x + mPenX, y + mPenY); }

    void SVGPathParser::lineTo(float x, float y) {
        // FLog.w(ReactConstants.TAG, "line x: " + x + " y: " + y);
        setPenDown();
        mPivotX = mPenX = x;
        mPivotY = mPenY = y;
        Point point = Point(x * mScale, y * mScale);
//         auto mPoints = std::vector<Point>();
        mPoints.push_back(point);
    }

    void SVGPathParser::arc(float rx, float ry, float rotation, bool outer, bool clockwise, float x, float y) {
        arcTo(rx, ry, rotation, outer, clockwise, x + mPenX, y + mPenY);
    }

    void SVGPathParser::arcTo(float rx, float ry, float rotation, bool outer, bool clockwise, float x, float y) {
        // FLog.w(ReactConstants.TAG, "arc rx: " + rx + " ry: " + ry + " rotation: " + rotation + " outer: " + outer + "
        // clockwise: " + clockwise + " x: " + x + " y: " + y);
        float tX = mPenX;
        float tY = mPenY;

        ry = abs(ry == 0 ? (rx == 0 ? (y - tY) : rx) : ry);
        rx = abs(rx == 0 ? (x - tX) : rx);

        if (rx == 0 || ry == 0 || (x == tX && y == tY)) {
            lineTo(x, y);
            return;
        }

        float rad = static_cast<float>(rotation * (M_PI / 180.0));
        float cos = std::cos(rad);
        float sin = std::sin(rad);
        x -= tX;
        y -= tY;

        // Ellipse Center
        float cx = cos * x / 2 + sin * y / 2;
        float cy = -sin * x / 2 + cos * y / 2;
        float rxry = rx * rx * ry * ry;
        float rycx = ry * ry * cx * cx;
        float rxcy = rx * rx * cy * cy;
        float a = rxry - rxcy - rycx;

        if (a < 0) {
            a = std::sqrt(1 - a / rxry);
            rx *= a;
            ry *= a;
            cx = x / 2;
            cy = y / 2;
        } else {
            a = std::sqrt(a / (rxcy + rycx));

            if (outer == clockwise) {
                a = -a;
            }
            float cxd = -a * cy * rx / ry;
            float cyd = a * cx * ry / rx;
            cx = cos * cxd - sin * cyd + x / 2;
            cy = sin * cxd + cos * cyd + y / 2;
        }

        // Rotation + Scale Transform
        float xx = cos / rx;
        float yx = sin / rx;
        float xy = -sin / ry;
        float yy = cos / ry;

        // Start and End Angle
        float sa = std::atan2(xy * -cx + yy * -cy, xx * -cx + yx * -cy);
        float ea = std::atan2(xy * (x - cx) + yy * (y - cy), xx * (x - cx) + yx * (y - cy));

        cx += tX;
        cy += tY;
        x += tX;
        y += tY;

        setPenDown();

        mPenX = mPivotX = x;
        mPenY = mPivotY = y;

        if (rx != ry || rad != 0.f) {
            //         arcToBezier(cx, cy, rx, ry, sa, ea, clockwise, rad);
        } else {

            float start = static_cast<float>(sa * 180.0 / M_PI);
            float end = static_cast<float>(ea * 180.0 / M_PI);
            float sweep = abs((start - end) - std::floor((start - end) / 360) * 360);


            if (outer) {
                if (sweep < 180) {
                    sweep = 360 - sweep;
                }
            } else {
                if (sweep > 180) {
                    sweep = 360 - sweep;
                }
            }

            if (!clockwise) {
                sweep = -sweep;
            }
            mArcRect.set((cx - rx) * mScale, (cy - rx) * mScale, (cx + rx) * mScale, (cy + rx) * mScale);
//             mArcRect = RectF((cx - rx) * mScale, (cy - rx) * mScale, (cx + rx) * mScale, (cy + rx) * mScale);


            //         mPath.arcTo(oval, start, sweep);
        }
    }

    void SVGPathParser::setPenDown() {
        if (!mPenDown) {
            mPenDownX = mPenX;
            mPenDownY = mPenY;
            mPenDown = true;
        }
    }
    void SVGPathParser::close() {
        if (mPenDown) {
            mPenX = mPenDownX;
            mPenY = mPenDownY;
            mPenDown = false;
            //         mPath.close();
        }
    }


    double SVGPathParser::_round(double val) {
        double multiplier = pow(10, 4);
        return round(val * multiplier) / multiplier;
    }

    void SVGPathParser::skip_spaces() {
        while (i < l && std::isspace(s.at(i)))
            i++;
    }
    bool SVGPathParser::is_cmd(char c) {
        switch (c) {
        case 'M':
        case 'm':
        case 'Z':
        case 'z':
        case 'L':
        case 'l':
        case 'H':
        case 'h':
        case 'V':
        case 'v':
        case 'C':
        case 'c':
        case 'S':
        case 's':
        case 'Q':
        case 'q':
        case 'T':
        case 't':
        case 'A':
        case 'a':
            return true;
        }
        return false;
    }


    bool SVGPathParser::is_number_start(char c) { return (c >= '0' && c <= '9') || c == '.' || c == '-' || c == '+'; }

    bool SVGPathParser::is_absolute(char c) { return std::isupper(c); }

    // By the SVG spec 'large-arc' and 'sweep' must contain only one char
    // and can be written without any separators, e.g.: 10 20 30 01 10 20.

    bool SVGPathParser::parse_flag() {
        skip_spaces();

        char c = s.at(i);
        switch (c) {
        case '0':
        case '1': {
            i += 1;
            if (i < l && s.at(i) == ',') {
                i += 1;
            }
            skip_spaces();
            break;
        }
        default:
            std::ostringstream oss;
            oss << "Unexpected flag" << c << ",i=" << i << ",s=" << s;
            throw std::logic_error(oss.str());
        }

        return c == '1';
    }


    float SVGPathParser::parse_list_number() {
        if (i == l) {
            std::ostringstream oss;
            oss << "Unexpected end (s=" << s << ")";
            throw std::logic_error(oss.str());
        }

        float n = parse_number();
        skip_spaces();
        parse_list_separator();

        return n;
    }


    float SVGPathParser::parse_number() {
        // Strip off leading whitespaces.
        skip_spaces();

        if (i == l) {
            std::ostringstream oss;
            oss << "Unexpected end (s=" << s << ")";
            throw std::logic_error(oss.str());
        }

        int start = i;

        char c = s.at(i);

        // Consume sign.
        if (c == '-' || c == '+') {
            i += 1;
            c = s.at(i);
        }

        // Consume integer.
        if (c >= '0' && c <= '9') {
            skip_digits();
            if (i < l) {
                c = s.at(i);
            }
        } else if (c != '.') {
            std::ostringstream oss;
            oss << "Invalid number formating character " << c << ",i=" << i << ",s=" << s;
            throw std::logic_error(oss.str());
        }

        // Consume fraction.
        if (c == '.') {
            i += 1;
            skip_digits();
            if (i < l) {
                c = s.at(i);
            }
        }

        if ((c == 'e' || c == 'E') && i + 1 < l) {
            char c2 = s.at(i + 1);
            // Check for `em`/`ex`.
            if (c2 != 'm' && c2 != 'x') {
                i += 1;
                c = s.at(i);

                if (c == '+' || c == '-') {
                    i += 1;
                    skip_digits();
                } else if (c >= '0' && c <= '9') {
                    skip_digits();
                } else {
                    std::ostringstream oss;
                    oss << "Invalid number formating character " << c << ",i=" << i << ",s=" << s;
                    throw std::logic_error(oss.str());
                }
            }
        }

        std::string num = s.substr(start, i);
        float n = std::stof(num);

        // inf, nan, etc. are an error.
        if (std::isinf(n) || std::isnan(n)) {
            std::ostringstream oss;
            oss << "Invalid number" << num << ",start=" << start << ",i=" << i << ",s=" << s;
            throw std::logic_error(oss.str());
        }

        return n;
    }

    void SVGPathParser::parse_list_separator() {
        if (i < l && s.at(i) == ',') {
            i += 1;
        }
    }

    void SVGPathParser::skip_digits() {
        while (i < l && std::isdigit(s.at(i)))
            i++;
    }
}; // namespace rnoh
