#include "Characters/Abilities/TargetDataFilters/GDNameTargetDataFilter.h"

#include "Characters/GDCharacterBase.h"

bool FGDNameTargetDataFilter::FilterPassesForActor(const AActor* ActorToBeFiltered) const
{
    if (const bool SuperValue = Super::FilterPassesForActor(ActorToBeFiltered))
    {
        if (const auto* GDCharacter = Cast<AGDCharacterBase>(ActorToBeFiltered))
        {
            const FString CharacterName = GDCharacter->GetCharacterName().ToString();
            const ESearchCase::Type SearchCase = CaseSensitive ? ESearchCase::CaseSensitive : ESearchCase::IgnoreCase;
            const bool ContainsName = CharacterName.Contains(Name, SearchCase);
            return (bReverseFilter ^ ContainsName);
        };
    }
    return false;
}
