#pragma once
#include "Components/CharacterComponent.h"

class EnemyComponent : public crae::CharacterComponent
{
public:
	CLASS_DECLARATION(EnemyComponent)

		virtual void Initialize() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(crae::Actor* other) override;
	virtual void OnCollisionExit(crae::Actor* other) override;

	virtual void OnNotify(const crae::Event& event) override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;

protected:
};