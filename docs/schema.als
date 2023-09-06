abstract sig Users {}
sig Accounts extends Users { toons: set Avatars }
sig Avatars extends Users { ownedBy: one Accounts }

fact allAvatarsAreClaimedByAnAccount { all a: Avatars, acc: Accounts | (a.ownedBy = acc) => (a in acc.toons) }
fact avatarsOwnedByAccount { all a: Avatars | one acc: Accounts | a.ownedBy = acc }

pred show{}

run show
