//
// Created on 2024/5/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef HARMONY_CLIPPATHVIEWNONEPACKAGE_H
#define HARMONY_CLIPPATHVIEWNONEPACKAGE_H

#include "RNOH/Package.h"
#include "ComponentDescriptors.h"
#include "ClipPathViewNoneJSIBinder.h"
#include "ClipPathViewNoneNapiBinder.h"

#include "ClipPathViewNoneComponentInstance.h"

namespace rnoh {
    class ClipPathViewNonePackageComponentInstanceFactoryDelegate : public ComponentInstanceFactoryDelegate {
    public:
        using ComponentInstanceFactoryDelegate::ComponentInstanceFactoryDelegate;

        ComponentInstance::Shared create(ComponentInstance::Context ctx) override {
            if (ctx.componentName == "RNCClipPathViewNone") {
                return std::make_shared<ClipPathViewNoneComponentInstance>(std::move(ctx));
            }
            return nullptr;
        }
    };

    class ClipPathViewNonePackage : public Package {
    public:
        ClipPathViewNonePackage(Package::Context ctx) : Package(ctx) {}

        ComponentInstanceFactoryDelegate::Shared createComponentInstanceFactoryDelegate() override {
            return std::make_shared<ClipPathViewNonePackageComponentInstanceFactoryDelegate>();
        }

        std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
            return {facebook::react::concreteComponentDescriptorProvider<
                facebook::react::RNCClipPathViewNoneComponentDescriptor>()};
        }

        ComponentJSIBinderByString createComponentJSIBinderByName() override {
            return {
                {"RNCClipPathViewNone", std::make_shared<ClipPathViewNoneJSIBinder>()},

            };
        }

        ComponentNapiBinderByString createComponentNapiBinderByName() override {
            return {
                {"RNCClipPathViewNone", std::make_shared<ClipPathViewNoneNapiBinder>()},
            };
        }
    };
}
#endif //HARMONY_CLIPPATHVIEWNONEPACKAGE_H
