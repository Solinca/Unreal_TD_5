#include "UI/PauseWidget.h"
#include "Components/Button.h"

void UPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ContinueButton->OnClicked.AddDynamic(this, &UPauseWidget::OnContinueButtonClickedEvent);

	RestartButton->OnClicked.AddDynamic(this, &UPauseWidget::OnRestartButtonClickedEvent);

	QuitButton->OnClicked.AddDynamic(this, &UPauseWidget::OnQuitButtonClickedEvent);
}

void UPauseWidget::OnContinueButtonClickedEvent()
{
	OnContinueButtonClicked.Broadcast();
}


void UPauseWidget::OnRestartButtonClickedEvent()
{
	OnRestartButtonClicked.Broadcast();
}

void UPauseWidget::OnQuitButtonClickedEvent()
{
	OnQuitButtonClicked.Broadcast();
}
