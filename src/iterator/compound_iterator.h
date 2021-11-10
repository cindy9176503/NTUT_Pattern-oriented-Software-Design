#pragma once

class CompoundIterator : public Iterator {
   public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) {}

    void first() override {}

    Article* currentItem() const override {}

    void next() override {}

    bool isDone() const override {}
};
