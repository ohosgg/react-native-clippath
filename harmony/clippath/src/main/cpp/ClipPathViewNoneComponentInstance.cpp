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

#include "ClipPathViewNoneComponentInstance.h"
#include <glog/logging.h>
namespace rnoh {
    ClipPathViewNoneComponentInstance::ClipPathViewNoneComponentInstance(Context context)
        : CppComponentInstance(std::move(context)) {}
    void ClipPathViewNoneComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance,
                                                            std::size_t index) {
        CppComponentInstance::onChildInserted(childComponentInstance, index);
        m_stackNode.insertChild(childComponentInstance->getLocalRootArkUINode(), index);
    }

    void ClipPathViewNoneComponentInstance::onChildRemoved(ComponentInstance::Shared const &childComponentInstance) {
        CppComponentInstance::onChildRemoved(childComponentInstance);
        m_stackNode.removeChild(childComponentInstance->getLocalRootArkUINode());
    };

    ClipPathViewNoneStackNode &ClipPathViewNoneComponentInstance::getLocalRootArkUINode() { return m_stackNode; }

    void ClipPathViewNoneComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
        CppComponentInstance::onPropsChanged(props);
        if (auto p = std::dynamic_pointer_cast<const facebook::react::RNCClipPathViewNoneProps>(props)) {
            //             this->getNapiProps(props);
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> d: " << p->d;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> mOpacity: " << p->opacity;
            //             LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> mMask: " << p->mask;
            //             LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> mOldMask: " << p->oldMask;
            //             LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> mFillColor: " << p->fillColor;
            //             LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> mFillOpacity: " <<
            //             p->fillOpacity;
            //             LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> mFillRule: " << p->fillRule;
            //             LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> strokeColor: " <<
            //             p->strokeColor; LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> strokeOpacity:
            //             " << p->strokeOpacity; LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps>
            //             strokeWidth: " << p->strokeWidth; LOG(INFO) << "[clx]
            //             <ClipPathViewComponentInstance::setProps> strokeCap: " << p->strokeCap; LOG(INFO) << "[clx]
            //             <ClipPathViewComponentInstance::setProps> strokeJoin: " << p->strokeJoin; LOG(INFO) << "[clx]
            //             <ClipPathViewComponentInstance::setProps> strokeMiter: " << p->strokeMiter; LOG(INFO) <<
            //             "[clx] <ClipPathViewComponentInstance::setProps> strokeStart: " << p->strokeStart; LOG(INFO)
            //             << "[clx] <ClipPathViewComponentInstance::setProps> strokeEnd: " << p->strokeEnd; LOG(INFO)
            //             << "[clx] <ClipPathViewComponentInstance::setProps> shadowColor: " << p->shadowColor;
            //             LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> shadowOpacity: " <<
            //             p->shadowOpacity; LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> shadowRadius:
            //             " << p->shadowRadius; LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps>
            //             shadowOffsetX: " << p->shadowOffsetX; LOG(INFO) <<
            //             "[clx] <ClipPathViewComponentInstance::setProps> shadowOffsetY: " << p->shadowOffsetY;
            //             LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> shadowOffsetIsPercent: "
            //                       << p->shadowOffsetIsPercent;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> transX: " << p->transX;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> transY: " << p->transY;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> transPercentageValue: "
                      << p->transPercentageValue;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> rot: " << p->rot;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> rotO: " << p->rotO;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> rotOx: " << p->rotOx;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> rotOy: " << p->rotOy;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> rotPercentageValue: "
                      << p->rotPercentageValue;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> sc: " << p->sc;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> scX: " << p->scX;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> scY: " << p->scY;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> scO: " << p->scO;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> scOx: " << p->scOx;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> scOy: " << p->scOy;
            LOG(INFO) << "[clx] <ClipPathViewComponentInstance::setProps> scPercentageValue: " << p->scPercentageValue;

            this->getLocalRootArkUINode().setD(p->d);
            this->getLocalRootArkUINode().setAspect(p->aspect);
            //             this->getLocalRootArkUINode().setFillOpacity(p->opacity);

            //             this->getLocalRootArkUINode().setStrokeColor(p->strokeColor);
            //             this->getLocalRootArkUINode().setStrokeWidth(p->strokeWidth);
            //             this->getLocalRootArkUINode().setStrokeCap(p->strokeCap);
            //             this->getLocalRootArkUINode().setStrokeJoin(p->strokeJoin);
            //             this->getLocalRootArkUINode().setStrokeMiter(p->strokeMiter);
            //             this->getLocalRootArkUINode().setStrokeOpacity(p->strokeOpacity);
            //             this->getLocalRootArkUINode().setStrokeStart(p->strokeStart);
            //             this->getLocalRootArkUINode().setStrokeEnd(p->strokeEnd);


            //             this->getLocalRootArkUINode().setShadowColor(p->shadowColor);
            //             this->getLocalRootArkUINode().setShadowOpacity(p->shadowOpacity);
            //             this->getLocalRootArkUINode().setShadowRadius(p->shadowRadius);
            //             this->getLocalRootArkUINode().setShadowOffsetX(p->shadowOffsetX);
            //             this->getLocalRootArkUINode().setShadowOffsetY(p->shadowOffsetY);
            //             this->getLocalRootArkUINode().setShadowOffsetIsPercent(p->shadowOffsetIsPercent);
            //
            if (p->sc != 1.f) {
                this->getLocalRootArkUINode().setSc(p->sc);
            }
            if (p->scX != 1.f) {
                this->getLocalRootArkUINode().setScX(p->scX);
            }
            if (p->scY != 1.f) {
                this->getLocalRootArkUINode().setScY(p->scY);
            }
            this->getLocalRootArkUINode().setScO(p->scO);
            this->getLocalRootArkUINode().setScOx(p->scOx);
            this->getLocalRootArkUINode().setScOy(p->scOy);
            this->getLocalRootArkUINode().setScPercentageValue(p->scPercentageValue);

            this->getLocalRootArkUINode().setTransX(p->transX);
            this->getLocalRootArkUINode().setTransY(p->transY);
            this->getLocalRootArkUINode().setTransPercentageValue(p->transPercentageValue);

            this->getLocalRootArkUINode().setRot(p->rot);
            this->getLocalRootArkUINode().setRotO(p->rotO);
            this->getLocalRootArkUINode().setRotOx(p->rotOx);
            this->getLocalRootArkUINode().setRotOy(p->rotOy);
            this->getLocalRootArkUINode().setRotPercentageValue(p->rotPercentageValue);

            this->getLocalRootArkUINode().setAlign(p->align);
            this->getLocalRootArkUINode().setViewBox(p->viewBox);
        }
    }

    void ClipPathViewNoneComponentInstance::getNapiProps(facebook::react::Props::Shared props) {
        auto p = std::dynamic_pointer_cast<const facebook::react::RNCClipPathViewNoneProps>(props);

        this->opacityStatus = p->opacityStatus;
        if (!p->opacityStatus) {
            this->opacity = p->opacity;
        }
        this->aspect = p->aspect;
        //         this->mask = p->mask;
        //         this->oldMask = p->oldMask;

        //         if (!p->fillColorStatus) {
        //             this->fillColor = p->fillColor;
        //         }
        //         this->fillColorStatus = p->fillColorStatus;
        //
        //         if (!p->fillOpacityStatus) {
        //             this->fillOpacity = p->fillOpacity;
        //         }
        //         this->fillOpacityStatus = p->fillOpacityStatus;
        //
        //         if (!p->fillRuleStatus) {
        //             this->fillRule = p->fillRule;
        //         }
        this->fillRule = p->fillRule;
        //         this->fillRuleStatus = p->fillRuleStatus;

        if (!p->strokeColorStatus) {
            this->strokeColor = p->strokeColor;
        }
        this->strokeColorStatus = p->strokeColorStatus;

        if (!p->strokeOpacityStatus) {
            this->strokeOpacity = p->strokeOpacity;
        }
        this->strokeOpacityStatus = p->strokeOpacityStatus;

        if (!p->strokeWidthStatus) {
            this->strokeWidth = p->strokeWidth;
        }
        this->strokeWidthStatus = p->strokeWidthStatus;

        if (!p->strokeMiterStatus) {
            this->strokeMiter = p->strokeMiter;
        }
        this->strokeMiterStatus = p->strokeMiterStatus;

        this->strokeCap = p->strokeCap;
        this->strokeJoin = p->strokeJoin;

        if (!p->strokeStartStatus) {
            this->strokeStart = p->strokeStart;
        }
        this->strokeStartStatus = p->strokeStartStatus;

        if (!p->strokeEndStatus) {
            this->strokeEnd = p->strokeEnd;
        }
        this->strokeEndStatus = p->strokeEndStatus;


        //         if (!p->shadowColorStatus) {
        //             this->shadowColor = p->shadowColor;
        //         }
        //         this->shadowColorStatus = p->shadowColorStatus;
        //
        //         if (!p->shadowOpacityStatus) {
        //             this->shadowOpacity = p->shadowOpacity;
        //         }
        //         this->shadowOpacityStatus = p->shadowOpacityStatus;
        //
        //         if (!p->shadowRadiusStatus) {
        //             this->shadowRadius = p->shadowRadius;
        //         }
        //         this->shadowRadiusStatus = p->shadowRadiusStatus;
        //
        //         if (!p->shadowOffsetStatus) {
        //             this->shadowOffsetX = p->shadowOffsetX;
        //             this->shadowOffsetY = p->shadowOffsetY;
        //             this->shadowOffsetIsPercent = p->shadowOffsetIsPercent;
        //         }
        //         this->shadowOffsetStatus = p->shadowOffsetStatus;


        this->sc = p->sc;
        this->scX = p->scX;
        this->scY = p->scY;
        this->scO = p->scO;
        this->scOx = p->scOx;
        this->scOy = p->scOy;
        this->scPercentageValue = p->scPercentageValue;

        this->rot = p->rot;
        this->rotOx = p->rotOx;
        this->rotOy = p->rotOy;
        this->rotPercentageValue = p->rotPercentageValue;

        this->transX = p->transX;
        this->transY = p->transY;
        this->transPercentageValue = p->transPercentageValue;

        this->align = p->align;
        this->viewBox = p->viewBox;
    }
} // namespace rnoh