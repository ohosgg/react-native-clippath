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

#include "ClipPathViewStackNode.h"
#include "RNOH/arkui/NativeNodeApi.h"
#include <memory>
#include "RectF.h"
#include "SVGViewBox.h"
#include <glog/logging.h>
#include "SVGPathParser.h"
#include "Point.h"

namespace rnoh {
    ClipPathViewStackNode::ClipPathViewStackNode()
        : ArkUINode(NativeNodeApi::getInstance()->createNode(ArkUI_NodeType::ARKUI_NODE_STACK)) {}

    void ClipPathViewStackNode::insertChild(ArkUINode &child, std::size_t index) {
        maybeThrow(NativeNodeApi::getInstance()->addChild(m_nodeHandle, child.getArkUINodeHandle()));
    }

    void ClipPathViewStackNode::removeChild(ArkUINode &child) {
        maybeThrow(NativeNodeApi::getInstance()->removeChild(m_nodeHandle, child.getArkUINodeHandle()));
    }
    void ClipPathViewStackNode::setD(const std::string D) {
        if (D.empty()) {
            return;
        }
        rnoh::SVGPathParser::mScale = this->getDensity();
        rnoh::SVGPathParser::parse(D);
        ArkUI_NumberValue startPosition[] = {{.f32 = rnoh::SVGPathParser::mX}, {.f32 = rnoh::SVGPathParser::mY}};
        ArkUI_AttributeItem positionItem = {startPosition, sizeof(startPosition) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> positionItem: " << &positionItem;
        // TODO path not set position
        //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_POSITION, &positionItem));

        if (rnoh::SVGPathParser::mArcRect.width() > 0.f && rnoh::SVGPathParser::mArcRect.height() > 0.f &&
            rnoh::SVGPathParser::mArcRect.width() == rnoh::SVGPathParser::mArcRect.height()) {
            ArkUI_NumberValue arcValue[] = {{ArkUI_ClipType::ARKUI_CLIP_TYPE_CIRCLE},
                                            {.f32 = rnoh::SVGPathParser::mArcRect.width()},
                                            {.f32 = rnoh::SVGPathParser::mArcRect.height()}};
            ArkUI_AttributeItem arcItem = {arcValue, sizeof(arcValue) / sizeof(ArkUI_NumberValue)};
            LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> cirItem width: " << rnoh::SVGPathParser::mArcRect.width();
            LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> cirItem height: "
                      << rnoh::SVGPathParser::mArcRect.height();
            LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> cirItem: " << &arcItem;
            maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CLIP_SHAPE, &arcItem));
        }
        if (rnoh::SVGPathParser::mArcRect.width() > 0.f && rnoh::SVGPathParser::mArcRect.height() > 0.f &&
            rnoh::SVGPathParser::mArcRect.width() != rnoh::SVGPathParser::mArcRect.height()) {
            ArkUI_NumberValue arcValue[] = {{ArkUI_ClipType::ARKUI_CLIP_TYPE_ELLIPSE},
                                            {.f32 = rnoh::SVGPathParser::mArcRect.width()},
                                            {.f32 = rnoh::SVGPathParser::mArcRect.height()}};
            ArkUI_AttributeItem arcItem = {arcValue, sizeof(arcValue) / sizeof(ArkUI_NumberValue)};
            LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> arcItem width: " << rnoh::SVGPathParser::mArcRect.width();
            LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> arcItem height: "
                      << rnoh::SVGPathParser::mArcRect.width();
            LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> arcItem: " << &arcItem;
            maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CLIP_SHAPE, &arcItem));
        }
        if (!rnoh::SVGPathParser::mPoints.empty()) {
            if (rnoh::SVGPathParser::mPoints.size() == 4) {
                float width = rnoh::SVGPathParser::mPoints[3].x - rnoh::SVGPathParser::mX;
                float height = rnoh::SVGPathParser::mPoints[1].y - rnoh::SVGPathParser::mY;
                ArkUI_NumberValue recValue[] = {
                    {ArkUI_ClipType::ARKUI_CLIP_TYPE_RECTANGLE}, {.f32 = width}, {.f32 = height}, {0.f}, {0.f}};
                ArkUI_AttributeItem recItem = {recValue, sizeof(recValue) / sizeof(ArkUI_NumberValue)};
                LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> recItem width: " << width;
                LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> recItem: height" << height;
                LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> recItem: " << &recItem;
                maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CLIP_SHAPE, &recItem));
            } else {
                for (const auto &point : rnoh::SVGPathParser::mPoints) {
                    float width = point.x - rnoh::SVGPathParser::mX;
                    float height = point.y - rnoh::SVGPathParser::mY;
                    ArkUI_NumberValue pathValue[] = {
                        {ArkUI_ClipType::ARKUI_CLIP_TYPE_PATH}, {.f32 = width}, {.f32 = height}};
                    ArkUI_AttributeItem pathItem = {pathValue, sizeof(pathValue) / sizeof(ArkUI_NumberValue)};
                    LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> pathItem: w" << width;
                    LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> pathItem: h" << height;
                    LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> pathItem: " << &pathItem;
                    maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CLIP_SHAPE, &pathItem));
                }
            }
        }
    }
    void ClipPathViewStackNode::setOpacity(const float opacity) {
        ArkUI_NumberValue indexValue[] = {{.f32 = opacity}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setOpacity> indexItem: " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_OPACITY, &indexItem));
    }
    void ClipPathViewStackNode::setAspect(const std::string aspect) {
        int p = aspect.empty()        ? rnoh::SVGViewBox::MOS_MEET
                : (aspect == "slice") ? rnoh::SVGViewBox::MOS_SLICE
                                      : (aspect == "none" ? rnoh::SVGViewBox::MOS_NONE : rnoh::SVGViewBox::MOS_MEET);
        ArkUI_NumberValue indexValue[] = {{.i32 = p}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setAspect> indexItem: " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_ASPECT_RATIO, &indexItem));
    }
    //     void ClipPathViewStackNode::setMask(const std::string mask) {
    //         ArkUI_AttributeItem indexItem = {.string = mask.c_str()};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setMask> indexItem: " << &indexItem;
    //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_MASK, &indexItem));
    //
    //     }
    //
    //     void ClipPathViewStackNode::setOldMask(const std::string oldMask) {
    //         ArkUI_AttributeItem indexItem = {.string = oldMask.c_str()};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setOldMask> indexItem: " << &indexItem;
    //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_MARK_ANCHOR, &indexItem));
    //
    //     }

    //     void ClipPathViewStackNode::setFillColor(const int &FillColor) {
    //         ArkUI_NumberValue indexValue[] = {{.i32 = FillColor}};
    //         ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setFillColor> indexItem: " << &indexItem;
    //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_BACKGROUND_COLOR, &indexItem));

    //     }
    //
    //     void ClipPathViewStackNode::setFillOpacity(const float &FillOpacity) {
    //         ArkUI_NumberValue indexValue[] = {{.f32 = FillOpacity}};
    //         ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setFillOpacity> indexItem: " << &indexItem;
    //         // maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, , &indexItem));

    //     }

    void ClipPathViewStackNode::setFillRule(const std::string rule) {
        ArkUI_AttributeItem indexItem = {.string = rule.c_str()};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setFillRule> indexItem: " << &indexItem;
        // maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, , &indexItem));
    }

    void ClipPathViewStackNode::setStrokeColor(const int strokeColor) {
        ArkUI_NumberValue indexValue[] = {{.i32 = strokeColor}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setStrokeColor> indexItem: " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_BORDER_COLOR, &indexItem));
    }

    void ClipPathViewStackNode::setStrokeOpacity(const float StrokeOpacity) {
        ArkUI_NumberValue indexValue[] = {{.f32 = StrokeOpacity}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setStrokeOpacity> indexItem: " << &indexItem;
    }

    void ClipPathViewStackNode::setStrokeWidth(const float StrokeWidth) {
        ArkUI_NumberValue indexValue[] = {{.f32 = StrokeWidth}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setStrokeWidth> indexItem: " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_BORDER_WIDTH, &indexItem));
    }

    void ClipPathViewStackNode::setStrokeCap(const std::string StrokeCap) {
        ArkUI_AttributeItem indexItem = {.string = StrokeCap.c_str()};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setStrokeCap> indexItem: " << &indexItem;
    }

    void ClipPathViewStackNode::setStrokeJoin(const std::string &StrokeJoin) {
        ArkUI_AttributeItem indexItem = {.string = StrokeJoin.c_str()};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setStrokeJoin> indexItem: " << &indexItem;
    }

    void ClipPathViewStackNode::setStrokeMiter(const float &StrokeMiter) {
        ArkUI_NumberValue indexValue[] = {{.f32 = StrokeMiter}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setStrokeMiter> indexItem: " << &indexItem;
    }

    void ClipPathViewStackNode::setStrokeStart(const float &StrokeStart) {
        ArkUI_NumberValue indexValue[] = {{.f32 = StrokeStart}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setStrokeStart> indexItem: " << &indexItem;
    }

    void ClipPathViewStackNode::setStrokeEnd(const float &StrokeEnd) {
        ArkUI_NumberValue indexValue[] = {{.f32 = StrokeEnd}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setStrokeEnd> indexItem: " << &indexItem;
    }
    //
    //     void ClipPathViewStackNode::setShadowColor(const int &shadowColor) {
    //         ArkUI_NumberValue indexValue[] = {{.f32 = this->shadowRadius},
    //                                           0,
    //                                           {.f32 = this->shadowOffsetX},
    //                                           {.f32 = this->shadowOffsetY},
    //                                           ARKUI_SHADOW_TYPE_COLOR,
    //                                           {.i32 = shadowColor},
    //                                           0};
    //         ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setShadowColor> indexItem: " << &indexItem;
    //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CUSTOM_SHADOW, &indexItem));
    //     }
    //
    //     void ClipPathViewStackNode::setShadowOpacity(const float &shadowOpacity) {
    //         ArkUI_NumberValue indexValue[] = {{.f32 = this->shadowRadius},
    //                                           0,
    //                                           {.f32 = this->shadowOffsetX},
    //                                           {.f32 = this->shadowOffsetY},
    //                                           ARKUI_SHADOW_TYPE_COLOR,
    //                                           {.u32 = this->shadowColor},
    //                                           0};
    //         ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setShadowOpacity> indexItem: " << &indexItem;
    //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CUSTOM_SHADOW, &indexItem));
    //     }
    //
    //     void ClipPathViewStackNode::setShadowRadius(const float &shadowRadius) {
    //         ArkUI_NumberValue indexValue[] = {{.f32 = shadowRadius},
    //                                           0,
    //                                           {.f32 = this->shadowOffsetX},
    //                                           {.f32 = this->shadowOffsetY},
    //                                           ARKUI_SHADOW_TYPE_COLOR,
    //                                           {.u32 = this->shadowColor},
    //                                           0};
    //         ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setShadowRadius> indexItem: " << &indexItem;
    //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CUSTOM_SHADOW, &indexItem));
    //     }
    //
    //  void ClipPathViewStackNode::setShadowOffsetX(const float &shadowOffsetX) {
    //         ArkUI_NumberValue indexValue[] = {{.f32 = this->shadowRadius},
    //                                           0,
    //                                           {.f32 = shadowOffsetX},
    //                                           {.f32 = this->shadowOffsetY},
    //                                           ARKUI_SHADOW_TYPE_COLOR,
    //                                           {.u32 = this->shadowColor},
    //                                           0};
    //         ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setShadowOffsetX> indexItem: " << &indexItem;
    //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CUSTOM_SHADOW, &indexItem));
    //     }
    //     void ClipPathViewStackNode::setShadowOffsetY(const float &shadowOffsetY) {
    //         ArkUI_NumberValue indexValue[] = {{.f32 = this->shadowRadius},
    //                                           0,
    //                                           {.f32 = this->shadowOffsetX},
    //                                           {.f32 = shadowOffsetY},
    //                                           ARKUI_SHADOW_TYPE_COLOR,
    //                                           {.u32 = this->shadowColor},
    //                                           0};
    //         ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setShadowOffsetY> indexItem: " << &indexItem;
    //         maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CUSTOM_SHADOW, &indexItem));
    //     }
    //     void ClipPathViewStackNode::setShadowOffsetIsPercent(const bool &shadowOffsetIsPercent)
    //     {
    //         ArkUI_NumberValue indexValue[] = {{static_cast<float>(shadowOffsetIsPercent)}};
    //         ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
    //         LOG(INFO) << "[clx] <ClipPathViewStackNode::setShadowOffsetIsPercent> indexItem: " << &indexItem;
    //         // maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CUSTOM_SHADOW,
    //     }
    void ClipPathViewStackNode::setBgColor(const int &bgColor) {
        ArkUI_NumberValue indexValue[] = {{.i32 = bgColor}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setBgColor> indexItem: " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_BACKGROUND_COLOR, &indexItem));
    }

    bool ClipPathViewStackNode::validateViewBox() { return rectFVb.width() >= 0.f && rectFVb.height() >= 0.f; }

    float ClipPathViewStackNode::toDip(float value) {
        Display metrics(getDensity());
        float valueInDip = TypedValue::applyDimension(TypedValue::COMPLEX_UNIT_DIP, value, metrics);
        return valueInDip;
    }

    void ClipPathViewStackNode::transform() {
        const ArkUI_AttributeItem *widthItem = NativeNodeApi::getInstance()->getAttribute(m_nodeHandle, NODE_WIDTH);
        const ArkUI_AttributeItem *heightItem = NativeNodeApi::getInstance()->getAttribute(m_nodeHandle, NODE_HEIGHT);
        // trans
        if (this->transX != 0.f || this->transY != 0.f) {
            float tX;
            float tY;
            if (this->transPercentageValue) {
                //                 LOG(INFO) << "[clx] <ClipPathViewStackNode::trans::widthItem " << &widthItem;
                //                 LOG(INFO) << "[clx] <ClipPathViewStackNode::trans::heightItem " << &heightItem;
                if (widthItem && heightItem) {
                    tX = (this->transX * widthItem->value[0].f32);
                    tY = (this->transY * heightItem->value[0].f32);
                }
            } else if (validateViewBox()) {
                tX = this->transX / rectFVb.width() * rectF.width();
                tY = this->transY / rectFVb.height() * rectF.height();
            } else {
                tX = toDip(this->transX);
                tY = toDip(this->transY);
            }
            // TODO 以获取sc  可用全区vector  存储
            ArkUI_NumberValue indexValue[] = {{.f32 = this->transX}, {.f32 = this->transY}, 0.f};
            ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
            //             LOG(INFO) << "[clx] <ClipPathViewStackNode::trans> indexItem: " << &indexItem;
            maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_TRANSLATE, &indexItem));
        }
        // rot
        if (this->rot != 0.f) {
            float rX;
            float rY;
            if (this->rotPercentageValue) {
                //                 LOG(INFO) << "[clx] <ClipPathViewStackNode::rot::widthItem " << &widthItem;
                //                 LOG(INFO) << "[clx] <ClipPathViewStackNode::rot::heightItem " << &heightItem;
                if (widthItem && heightItem) {
                    rX = (this->rotOx * widthItem->value[0].f32);
                    rY = (this->rotOy * heightItem->value[0].f32);
                }
            } else if (validateViewBox()) {
                rX = rectF.left + modUtil.viewBoxToWidth(this->rotOx, rectFVb, rectF.width());
                rY = rectF.top + modUtil.viewBoxToHeight(this->rotOy, rectFVb, rectF.height());
            } else {
                rX = toDip(this->rotOx);
                rY = toDip(this->rotOy);
            }
            // TODO get rote  vector  save
            ArkUI_NumberValue indexValue[] = {
                {.f32 = this->rotOx}, {.f32 = this->rotOx}, 0.f, {.f32 = this->rot}, 0.0f};
            ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
            //             LOG(INFO) << "[clx] <ClipPathViewStackNode::rote> indexItem: " << &indexItem;
            maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_ROTATE, &indexItem));
        }
        // scale
        if (this->scX != 1.f || this->scY != 1.f) {
            float oX;
            float oY;
            if (this->scPercentageValue) {
                //                 LOG(INFO) << "[clx] <ClipPathViewStackNode::sc::widthItem " << &widthItem;
                //                 LOG(INFO) << "[clx] <ClipPathViewStackNode::sc::heightItem " << &heightItem;
                if (widthItem && heightItem) {
                    oX = (this->scOx * widthItem->value[0].f32);
                    oY = (this->scOy * heightItem->value[0].f32);
                }
            } else if (validateViewBox()) {
                oX = rectF.left + modUtil.viewBoxToWidth(this->scOx, rectFVb, rectF.width());
                oY = rectF.top + modUtil.viewBoxToHeight(this->scOy, rectFVb, rectF.height());
            } else {
                oX = toDip(this->scOx);
                oY = toDip(this->scOy);
            }
            // TODO get rote  vector  save
            ArkUI_NumberValue indexValue[] = {{.f32 = this->scOx}, {.f32 = this->scOy}};
            ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
            //             LOG(INFO) << "[clx] <ClipPathViewStackNode::sc> indexItem: " << &indexItem;
            maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SCALE, &indexItem));
        }
    }

    void ClipPathViewStackNode::setSc(float v) {
        if (this->scX == v && this->scY == v) {
            return;
        }
        this->scX = v;
        this->scY = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->scX}, {.f32 = this->scY}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setSc>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SCALE, &indexItem));
    }

    void ClipPathViewStackNode::setScX(float v) {
        if (this->scX == v) {
            return;
        }
        this->scX = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->scX}, {.f32 = this->scY}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setScX>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SCALE, &indexItem));
    }

    void ClipPathViewStackNode::setScY(float v) {
        if (this->scY == v) {
            return;
        }
        this->scY = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->scX}, {.f32 = this->scY}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setScY>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SCALE, &indexItem));
    }

    void ClipPathViewStackNode::setScO(float v) {
        if (this->scOx == v && this->scOy == v) {
            return;
        }
        this->scOx = v;
        this->scOy = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->scOx}, {.f32 = this->scOy}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setScO>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SCALE, &indexItem));
    }

    void ClipPathViewStackNode::setScOx(float v) {
        if (this->scOx == v) {
            return;
        }
        this->scOx = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->scOx}, {.f32 = this->scOy}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setscOx>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SCALE, &indexItem));
    }

    void ClipPathViewStackNode::setScOy(float v) {
        if (this->scOy == v) {
            return;
        }
        this->scOy = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->scOx}, {.f32 = this->scOy}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setscOy>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SCALE, &indexItem));
    }

    void ClipPathViewStackNode::setScPercentageValue(bool v) {
        if (this->scPercentageValue == v) {
            return;
        }
        this->scPercentageValue = v;
        this->transform();
        ArkUI_NumberValue indexValue[] = {{.f32 = this->scOx}, {.f32 = this->scOy}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setScPercentageValue>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SCALE, &indexItem));
    }

    void ClipPathViewStackNode::setTransX(float v) {
        if (this->transX == v) {
            return;
        }
        this->transX = v;
        ArkUI_NumberValue indexValue[] = {
            {static_cast<float>(this->transX)}, {static_cast<float>(this->transY)}, {0.0f}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setTransX>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_TRANSLATE, &indexItem));
    }

    void ClipPathViewStackNode::setTransY(float v) {
        if (this->transY == v) {
            return;
        }
        this->transY = v;
        ArkUI_NumberValue indexValue[] = {
            {static_cast<float>(this->transX)}, {static_cast<float>(this->transY)}, {0.0f}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setTransY>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_TRANSLATE, &indexItem));
    }

    void ClipPathViewStackNode::setTransPercentageValue(bool v) {
        if (this->transPercentageValue == v) {
            return;
        }
        this->transPercentageValue = v;
        this->transform();
        ArkUI_NumberValue indexValue[] = {
            {static_cast<float>(this->transX)}, {static_cast<float>(this->transY)}, {0.0f}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setTransPercentageValue>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_TRANSLATE, &indexItem));
    }

    void ClipPathViewStackNode::setRot(float v) {
        if (this->rot == v) {
            return;
        }
        this->rot = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->rotOx}, {.f32 = this->rotOy}, 0.0f, {.f32 = this->rot}, 0.0f};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setRot> " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_ROTATE, &indexItem));
    }

    void ClipPathViewStackNode::setRotO(float v) {
        if (this->rotOx == v && this->rotOy == v) {
            return;
        }
        this->rotOx = v;
        this->rotOy = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->rotOx}, {.f32 = this->rotOy}, 0.0f, {.f32 = this->rot}, 0.0f};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setRotO>" << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_ROTATE, &indexItem));
    }

    void ClipPathViewStackNode::setRotOx(float v) {
        if (this->rotOx == v) {
            return;
        }
        this->rotOx = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->rotOx}, {.f32 = this->rotOy}, 0.0f, {.f32 = this->rot}, 0.0f};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setRotOx> " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_ROTATE, &indexItem));
    }

    void ClipPathViewStackNode::setRotOy(float v) {
        if (this->rotOy == v) {
            return;
        }
        this->rotOy = v;
        ArkUI_NumberValue indexValue[] = {{.f32 = this->rotOx}, {.f32 = this->rotOy}, 0.0f, {.f32 = this->rot}, 0.0f};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setRotOy> " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_ROTATE, &indexItem));
    }


    void ClipPathViewStackNode::setRotPercentageValue(bool v) {
        if (this->rotPercentageValue == v) {
            return;
        }
        this->rotPercentageValue = v;
        this->transform();
        ArkUI_NumberValue indexValue[] = {{.f32 = this->rotOx}, {.f32 = this->rotOy}, 0.0f, {.f32 = this->rot}, 0.0f};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::rotPercentageValue> " << &indexItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_ROTATE, &indexItem));
    }
    void ClipPathViewStackNode::setAlign(std::string align) {
        if (this->align == align) {
            return;
        }
        this->align = align;
        std::vector<float> transformResult = rnoh::SVGViewBox::transform(rectFVb, rectF, this->align, 0, getDensity());
        setScX(transformResult[0]);
        setScY(transformResult[1]);
        setTransX(transformResult[2]);
        setTransY(transformResult[3]);
    }

    float ClipPathViewStackNode::getDensity() { return 2.5f; }
    void ClipPathViewStackNode::setViewBox(const std::vector<float> &viewBox) {
        if (viewBox.empty())
            return;
        float density = getDensity();
        rectFVb.set(viewBox[0], viewBox[1], (viewBox[0] + viewBox[2]), (viewBox[1] + viewBox[3]));
        rectFVbDensity.set(viewBox[0] * density, viewBox[1] * density, (viewBox[0] + viewBox[2]) * density,
                           (viewBox[1] + viewBox[3]) * density);
        float width = rectFVbDensity.width();
        float height = rectFVbDensity.height();
        ArkUI_NumberValue recValue[] = {
            {ArkUI_ClipType::ARKUI_CLIP_TYPE_RECTANGLE}, {.f32 = width}, {.f32 = height}, {0.f}, {0.f}};
        ArkUI_AttributeItem recItem = {recValue, sizeof(recValue) / sizeof(ArkUI_NumberValue)};
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> setViewBox width: " << width;
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> setViewBox: height" << height;
        LOG(INFO) << "[clx] <ClipPathViewStackNode::setD> setViewBox: " << &recItem;
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CLIP_SHAPE, &recItem));
    }

} // namespace rnoh
