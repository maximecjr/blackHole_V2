// Copyright Epic Games, Inc. All Rights Reserved.

#include "ASActionSystemComponent.h"

UASActionSystemComponent::UASActionSystemComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UASActionSystemComponent::SetAttributeValue(FGameplayTag AttributeTag, float Value)
{
    for (FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            Attr.CurrentValue = FMath::Clamp(Value, Attr.MinValue, Attr.MaxValue);
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::GetAttributeValue(FGameplayTag AttributeTag, float& OutValue) const
{
    for (const FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            OutValue = Attr.CurrentValue;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::SetAttributeMaxValue(FGameplayTag AttributeTag, float Value)
{
    for (FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            Attr.MaxValue = Value;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::GetAttributeMaxValue(FGameplayTag AttributeTag, float& OutValue) const
{
    for (const FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            OutValue = Attr.MaxValue;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::SetAttributeMinValue(FGameplayTag AttributeTag, float Value)
{
    for (FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            Attr.MinValue = Value;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::GetAttributeMinValue(FGameplayTag AttributeTag, float& OutValue) const
{
    for (const FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            OutValue = Attr.MinValue;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::HasAttribute(FGameplayTag AttributeTag) const
{
    for (const FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::AddAttribute(const FASAttribute& NewAttribute)
{
    if (!HasAttribute(NewAttribute.AttributeTag))
    {
        Attributes.Add(NewAttribute);
        return true;
    }
    return false;
}

bool UASActionSystemComponent::RemoveAttribute(FGameplayTag AttributeTag)
{
    for (int32 i = 0; i < Attributes.Num(); ++i)
    {
        if (Attributes[i].AttributeTag == AttributeTag)
        {
            Attributes.RemoveAt(i);
            return true;
        }
    }
    return false;
}
