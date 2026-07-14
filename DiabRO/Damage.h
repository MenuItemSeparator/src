#pragma once

namespace DiabroNS {

class Damage 
{
public:
    int Calculate(block_list *src,block_list *bl,struct Damage *d,int64 damage,uint16 skill_id,uint16 skill_lv);
    int Apply(int _atk, int _def);
};

}
