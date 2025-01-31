#include "MCP.h"
#include "Utils.h"


namespace MCP {

    void Register() {
        if (!SKSEMenuFramework::IsInstalled()) {
            logger::warn("SKSE Menu Framework is not installed. Cannot register menu.");
            return;
        }
        SKSEMenuFramework::SetSection("Immersive Weapon Switch");
        SKSEMenuFramework::AddSectionItem("Settings", RenderSettings);

        logger::info("SKSE Menu Framework registered.");
    }

    void __stdcall RenderSettings() {
        if (ImGui::Button("Save Settings")) {
            Settings::SaveSettings();
        }
        if (ImGui::Button("Reset Settings")) {
            Settings::ResetSettings();
        }

        ImGui::Checkbox("Mod Active", &Settings::Mod_Active);

        ImGui::Checkbox("Hold 'R' To Drop", &Settings::Hold_To_Drop);
        ImGui::SliderFloat("Held Duration To Drop (sec)", &Settings::Held_Duration, 0, 10, "%.3f");

        ImGui::Checkbox("NPC Drop Weapons On Change", &Settings::NPC_Drop_Weapons);
        ImGui::Checkbox("PC Drop Weapons On Change", &Settings::PC_Drop_Weapons);

        ImGui::SliderFloat("NPC Health % to Drop", &Settings::NPC_Health_Drop, 0, 100, "%.0f");
        ImGui::SliderFloat("PC Health % to Drop", &Settings::PC_Health_Drop, 0, 100, "%.0f");
    }

}