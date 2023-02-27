#include "stdafx.h"
#include "PartCount.h"

PartCount::PartCount()
{
}


PartCount::~PartCount()
{
}


void PartCount::ParseLine(const ArgScript::Line& line)
{
	using namespace Editors;
	if (Editor.IsActive()) {
		if (Editor.IsMode(Mode::BuildMode)) {
			App::ConsolePrintF("The number of part is: %d", Editor.GetEditorModel()->GetRigblocksCount());
			if (Editor.GetEditorModel()->GetRigblocksCount() >= 255) {
				App::ConsolePrintF("Number of part is at limits.");
			}
		}
		else {
			App::ConsolePrintF("The cheat can only be used in build mode.");
		}
	}
	else {
		App::ConsolePrintF("Enter an editor to use this cheat.");
	}
}

const char* PartCount::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Show how many parts currently in the editor.";
	}
	else {
		return "PartCount: Show how many parts currently in the editor.";
	}
}
