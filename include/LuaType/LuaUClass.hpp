#ifndef UE4SS_REWRITTEN_LUAUCLASS_HPP
#define UE4SS_REWRITTEN_LUAUCLASS_HPP

#include <LuaMadeSimple/LuaObject.hpp>
#include <LuaType/LuaUObject.hpp>
#include <LuaType/LuaUStruct.hpp>

namespace RC::Unreal
{
    class UClass;
}

namespace RC::LuaType
{
    struct UClassName { constexpr static const char* ToString() { return "UClass"; }};
    class UClass : public UObjectBase<Unreal::UClass, UClassName>
    {
    public:
        using Super = LuaType::UStruct;

    private:
        explicit UClass(Unreal::UClass* object);

    public:
        auto derives_from_class() -> bool override { return true; }

    public:
        UClass() = delete;
        auto static construct(const LuaMadeSimple::Lua&, Unreal::UClass*) -> const LuaMadeSimple::Lua::Table;
        auto static construct(const LuaMadeSimple::Lua&, BaseObject&) -> const LuaMadeSimple::Lua::Table;

    private:
        auto static setup_metamethods(BaseObject&) -> void;

    public:
        template<LuaMadeSimple::Type::IsFinal is_final>
        auto static setup_member_functions(const LuaMadeSimple::Lua::Table&, std::string_view) -> void;
    };
}


#endif //UE4SS_REWRITTEN_LUAUCLASS_HPP
