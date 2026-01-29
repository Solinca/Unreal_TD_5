#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClickedSignature);

UCLASS()
class TD_5_NICOLAS_CORBI_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnContinueButtonClickedEvent();

	UFUNCTION()
	void OnRestartButtonClickedEvent();

	UFUNCTION()
	void OnQuitButtonClickedEvent();
	
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> ContinueButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> RestartButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> QuitButton = nullptr;

public:
	FOnButtonClickedSignature OnContinueButtonClicked;

	FOnButtonClickedSignature OnRestartButtonClicked;

	FOnButtonClickedSignature OnQuitButtonClicked;
};
