namespace Platform::Data::Tests
{
    template<typename TLink, typename TWriteHandler = std::function<typename TLink::value_type(TLink, TLink)>, typename TReadHandler = std::function<typename TLink::value_type(TLink)>, LinksConstants<typename TLink::value_type> VConstants = LinksConstants<typename TLink::value_type>{true}>
    struct Links : public ILinks<LinksOptions<TLink, TWriteHandler, TReadHandler, VConstants>>
    {
        using base = ILinks<LinksOptions<TLink, TWriteHandler, TReadHandler, VConstants>>;
        using typename base::LinkAddressType;
        using typename base::LinkType;
        using typename base::WriteHandlerType;
        using typename base::ReadHandlerType;
        using base::Constants;

        LinkAddressType Count(const LinkType& restriction) const override { return 0; };

        LinkAddressType Each(const LinkType& restriction, const ReadHandlerType& handler) const override { return 0; };

        LinkAddressType Create(const LinkType& restriction, const WriteHandlerType& handler) override { return 0; };

        LinkAddressType Update(const LinkType& restriction, const LinkType& substitution, const WriteHandlerType& handler) override { return 0; };

        LinkAddressType Delete(const LinkType& restriction, const WriteHandlerType& handler) override { return 0; };
    };
    TEST(ILinksDeriverTest, ConstructorAndMethodsTest)
    {
        using TLinkAddress = uint64_t;
        using TLink = std::vector<TLinkAddress>;
        using TWriteHandler = std::function<TLinkAddress(TLink, TLink)>;
        using TReadHandler = std::function<TLinkAddress(TLink)>;
        Links<TLink> storage{};
        const Links<TLink> const_links {storage};
        const TLinkAddress linkAddress {1};
        Create(storage, linkAddress);
        Update(storage, std::vector<TLinkAddress>{1}, std::vector<TLinkAddress>{1, 1});
        storage.Count(std::vector<TLinkAddress>{1});
        const_links.Count(std::vector<TLinkAddress>{1});
        storage.Each(std::vector<TLinkAddress>{1}, [](const TLink& link){ return 1; });
        const_links.Each(std::vector<TLinkAddress>{1}, [](const TLink& link){ return 1; });
        Delete(storage, std::vector<TLinkAddress>{1});
    }
}
