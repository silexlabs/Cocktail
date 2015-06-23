package core.url;

import buddy.*;
using buddy.Should;

import cocktail.core.url.URL;

class URLTest extends BuddySuite {

    public function new()
    {
        describe('URL parsing and serializing', function () {
            describe('#fromString', function () {
                it('should parse an URL', function () {
                    var url = URL.fromString('http://www.domain.com/');
                    url.host.should.be('www.domain.com');
                    url.scheme.should.be('http');
                });

                it('should parse an URL with a path', function () {
                    var url = URL.fromString('http://www.domain.com/resource/');
                    url.path.should.be('/resource/');
                });
            });
        });
    }
}
